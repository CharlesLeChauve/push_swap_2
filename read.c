/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:18:27 by tgibert           #+#    #+#             */
/*   Updated: 2024/01/11 09:19:11 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_buffer(char *buffer, char *line)
{
	int		line_len;
	int		i;
	char	*newl;

	line_len = ft_strlen(line);
	i = -1;
	newl = (char *)malloc(line_len + 2);
	while (++i < line_len)
		newl[i] = line[i];
	newl[i++] = *buffer;
	newl[i] = '\0';
	free(line);
	return (newl);
}

t_instructs *read_stdin()
{
	int			bread;
	char		buffer[1];
	char		*instr;
	t_instructs	*instructs;

	instructs = (t_instructs *)malloc(sizeof(t_instructs));
	bread = 1;
	buffer[0] = 0;
	instr = malloc(1);
	while (bread > 0)
	{
		bread = read(0, buffer, 1);
		join_buffer(buffer, instr);
		buffer[0] = 0;
	}
	instructs->instructs = ft_split(instr, '\n');
	instructs->nb = 0;
	while (instructs->instructs[instructs->nb])
		instructs->nb++;
	return (instructs);
}