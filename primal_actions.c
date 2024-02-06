/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primal_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:43:49 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/06 08:11:04 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **pile)
{
	int		tmp;

	tmp = (*pile)->nb;
	if (pile_size(*pile) > 1)
	{
		(*pile)->nb = (*pile)->next->nb;
		(*pile)->next->nb = tmp;
	}
}

void	rotate(t_pile **pile)
{
	t_pile *node;

	node = *pile;
	if (!*pile || pile_size(*pile) < 2)
		return;
	*pile = (*pile)->next;
	pile_add_back(pile, node);
}

void	reverse_rotate(t_pile **pile)
{
	t_pile	*last_node;

	if (!*pile || pile_size(*pile) < 2)
		return;
	last_node = pile_last(*pile);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = *pile;
	(*pile)->prev = last_node;
	*pile = last_node;
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
		*src = node->next;
		pile_add_front(dst, node);
	}
}
