/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:22:38 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/07 08:30:28 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	destroy_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

t_pile	*create_first_pile(char **av)
{
	t_pile	*pile;
	t_pile	*new;
	char	**actual_arg;
	int		i;
	int		j;

	pile = NULL;
	i = 0;
	while (av[i])
	{
		actual_arg = ft_split(av[i], ' ');
		j = 0;
		while (actual_arg[j])
		{
			new = new_pile_node(ft_atoi(actual_arg[j]));
			pile_add_back(&pile, new);
			j++;
		}
		destroy_arg(actual_arg);
		i++;
	}
	return (pile);
}