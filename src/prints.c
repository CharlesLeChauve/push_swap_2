/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:40:04 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/08 09:23:20 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	t_pile *act_a;
	t_pile *act_b;

	act_a = ab.pile_a;
	act_b = ab.pile_b;
	ft_printf("Pile_a :\tPile_b :\n");
	if (act_a)
		ft_printf("%d\t\t", act_a->nb);
	if (act_b)
		ft_printf("%d\t\t\n", act_b->nb);
	else
		ft_printf("\n");
	act_a = act_a->next;
	if (act_b)
		act_b = act_b->next;
	while (act_a && act_a != ab.pile_a || act_b && act_b != ab.pile_b)
	{
		if (act_a && act_a != ab.pile_a)
		{
			ft_printf("%d\t\t", act_a->nb);
			act_a = act_a->next;
		}
		else
			ft_printf("\t\t");
		if (act_b && act_b != ab.pile_b)
		{
			ft_printf("%d\t\n", act_b->nb);
			act_b = act_b->next;
		}
		else
			ft_printf("\t\t\n");
	}
}

void	ft_perror(char *str)
{
	write(2, str, ft_strlen(str));
}
