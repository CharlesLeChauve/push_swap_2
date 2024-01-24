/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:40:04 by tgibert           #+#    #+#             */
/*   Updated: 2024/01/09 09:42:49 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile_reverse(t_pile *pile)
{
	t_pile *act;

	act = pile->prev;
	if (!act)
		return;
	while (act->prev != pile->prev)
	{
		ft_printf("%d\n", act->nb);
		act = act->prev;
	}
	ft_printf("%d\n", act->nb);
}

void	print_pile(t_pile *pile)
{
	t_pile *act;

	act = pile;
	if (!act)
		return;
	ft_printf("%d\n", act->nb);
	act = act->next;
	while (act && act != pile)
	{
		ft_printf("%d\n", act->nb);
		act = act->next;
	}
}

void	print_piles(t_ab ab)
{
	ft_printf("\tPile_a :\n===\n");
	print_pile(ab.pile_a);
	ft_printf("===\n");
	ft_printf("\tPile_b :\n===\n");
	print_pile(ab.pile_b);
	ft_printf("===\n");
}

void	ft_perror(char *str)
{
	write(2, str, ft_strlen(str));
}
