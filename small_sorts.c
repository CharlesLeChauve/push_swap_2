/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:11:42 by tgibert           #+#    #+#             */
/*   Updated: 2024/01/11 09:17:44 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_three(t_ab *ab)
{
	t_pile *pile;

	pile = ab->pile_a;
	if (pile->nb > pile->next->nb && pile->next->nb > pile->next->next->nb)
	{
		sa(ab);
		rra(ab);
	}
	else if (pile->nb > pile->next->nb && pile->next->nb < pile->next->next->nb
		&& pile->next->next->nb > pile->nb)
		sa(ab);
	else if (pile->nb > pile->next->nb && pile->next->nb < pile->next->next->nb
		&& pile->next->next->nb < pile->nb)
		ra(ab);
	else if (pile->nb < pile->next->nb && pile->next->nb > pile->next->next->nb
		&& pile->next->next->nb > pile->nb)
	{
		sa(ab);
		ra(ab);
	}
	else if (pile->nb < pile->next->nb && pile->next->nb > pile->next->next->nb
		&& pile->next->next->nb < pile->nb)
		rra(ab);
}
void	sort_ten(t_ab *ab)
{
	while (pile_size(ab->pile_a) > 3)
	{
		push_min_to_b(ab);
	}
	sort_three(ab);
	while (ab->pile_b)
	{
		pa(ab);	
	}
}

void	resolve_small(t_ab *ab)
{
	int	ps;

	ps = pile_size(ab->pile_a);
	if (ps <= 1)
		return;
	else if (ps == 2 && !is_sorted(ab->pile_a))
		sa(ab);
	else if (ps == 3)
		sort_three(ab);
 	else
		sort_ten(ab);
}
