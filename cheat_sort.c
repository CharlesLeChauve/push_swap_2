/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheat_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:44:15 by tgibert           #+#    #+#             */
/*   Updated: 2024/01/16 20:27:33 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*copy_node(t_pile *src_node)
{
	t_pile	*copy;

	copy = (t_pile *)malloc(sizeof(t_pile));
	copy->nb = src_node->nb;
	copy->next = NULL;
	copy->prev = NULL;
	return (copy);
}

t_pile	*copy_pile(t_pile *src_pile)
{
	t_pile	*copy;
	t_pile	*act_src;

	copy = copy_node(src_pile);
	act_src = src_pile->next;
	while (act_src != src_pile)
	{
		pile_add_back(&copy, copy_node(act_src));
		act_src = act_src->next;
	}
	return (copy);
}

t_pile *get_ith_next(t_pile *act, int i)
{
	int	j;
	t_pile *ith_next;

	j = 0;
	ith_next = act;
	while (j <= i)
	{
		ith_next = ith_next->next;
		j++;
	}
	return (ith_next);
}

void	swap_values(t_pile *first, t_pile *second)
{
		int	tmp_val;

		tmp_val = first->nb;
		first->nb = second->nb;
		second->nb = tmp_val;
}

t_pile	*cheat_sort(t_pile *src_pile)
{
	t_pile *sorted;
	t_pile *act;
	int 	i;
	int		j;
	int		size;

	i = 0;
	size = pile_size(src_pile);
	sorted = copy_pile(src_pile);
	while (i < size)
	{
		j = 0;
		act = sorted;
		while (j < size - i)
		{
			if (act->nb > act->next->nb)
				swap_values(act, act->next);
			act = act->next;
			j++;
		}
		i++;
	}
	//print_pile(sorted);
	return (sorted);
}

int	get_nthile(t_pile *pile, int n)
{
	int		index;
	int		i;
	int		nb;
	t_pile	*act;

	index = pile_size(pile) / n;
	i = 0;
	act = cheat_sort(pile);
	while (i < index)
	{
		act = act->next;
		i++;
	}
	nb = act->nb;
	destroy_pile(&act);
	return (nb);
}

int	get_median(t_pile *pile)
{
	int		index;
	int		i;
	int		nb;
	t_pile	*act;

	index = pile_size(pile) / 2;
	i = 0;
	act = cheat_sort(pile);
	while (i < index)
	{
		act = act->next;
		i++;
	}
	nb = act->nb;
	destroy_pile(&act);
	return (nb);
}
