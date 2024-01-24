/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primal_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:43:49 by tgibert           #+#    #+#             */
/*   Updated: 2024/01/10 09:49:44 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **pile)
{
	t_pile	*first;
	t_pile	*second;
	int		tmp_value;

	if (pile_size(*pile) > 1)
	{
		first = *pile;
		second = (*pile)->next;
		tmp_value = first->nb;
		first->nb = second->nb;
		second->nb = tmp_value;
	}
	set_index(*pile);
}

void	rotate(t_pile **pile)
{
	if (!*pile)
		return;
	*pile = (*pile)->next;
	set_index(*pile);
}

void	reverse_rotate(t_pile **pile)
{
	if (!*pile)
		return;
	*pile = (*pile)->prev;
	set_index(*pile);
}
void	push(t_pile **src, t_pile **dst)
{
	t_pile *node;

	if (!*src)
		return;
	else if (pile_size(*src) == 1)
	{
		pile_add_front(dst, *src);
		*src = NULL;
	}
	else
	{
		node = *src;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*src = node->next;
		pile_add_front(dst, node);
	}
	set_index(*src);
	set_index(*dst);
}
