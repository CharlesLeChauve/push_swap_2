/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 08:37:33 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/08 09:13:38 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

char	*read_instructions()
{
	int		bread;
	char	*buffer;
	char	*instructions;

	bread = 1;
	buffer = (char *)malloc(1);
	instructions = (char*)malloc(1);
	instructions[0] = 0;
	while (bread == 1)
	{
		buffer[0] = 0;
		bread = read(0, buffer, 1);
		instructions = join_buffer(buffer, instructions);
	}
	free(buffer);
	return (instructions);
}

char	**parse_instructions(char *raw)
{
	char	**instructions;

	instructions = ft_split(raw, '\n');
	return (instructions);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((int)((unsigned char) s1[i] - (unsigned char) s2[i]));
		i++;
	}
	return (0);
}

void	exec_action(t_ab *ab, char *instruct)
{
	if (!ft_strcmp(instruct, "pa"))
		spa(ab);
	if (!ft_strcmp(instruct, "pb"))
		spb(ab);
	if (!ft_strcmp(instruct, "sa"))
		ssa(ab);
	if (!ft_strcmp(instruct, "sb"))
		ssb(ab);
	if (!ft_strcmp(instruct, "ra"))
		sra(ab);
	if (!ft_strcmp(instruct, "rb"))
		srb(ab);
	if (!ft_strcmp(instruct, "rra"))
		srra(ab);
	if (!ft_strcmp(instruct, "rrb"))
		srrb(ab);
	if (!ft_strcmp(instruct, "ss"))
		sss(ab);
	if (!ft_strcmp(instruct, "rr"))
		srr(ab);
}

int	main(int argc, char *argv[])
{
	t_ab	ab;
	char	*raw_instructions;
	char	**instructions;
	int		i;

	ab.pile_b = NULL;
	i = 0;
	if (argc < 2)
		exit(0);
	else
		ab.pile_a = create_first_pile(argv + 1);
	raw_instructions = read_instructions();
	instructions = parse_instructions(raw_instructions);
	while (instructions[i])
	{
		ft_printf("action n: %d, action = %s\n", i, instructions[i]);
		exec_action(&ab, instructions[i]);
		i++;
	}
	print_piles(ab);
	if (is_sorted(ab.pile_a) && !ab.pile_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
