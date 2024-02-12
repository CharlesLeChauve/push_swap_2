/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:40:18 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/07 08:30:28 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_pile *pile)
{
	int	index;

	index = 0;
	while (pile)
	{
		pile->index = index;
		pile = pile->next;
		index++;
	}
}

int	is_sorted(t_pile *pile)
{
	int	prev_nb;

	prev_nb = pile->nb;
	pile = pile->next;
	while (pile)
	{
		if (pile->nb < prev_nb)
			return (0);
		pile = pile->next;
	}
	return (1);
}

t_pile	*get_lower(t_pile *pile)
{
	t_pile	*act;
	t_pile	*lower;

	lower = pile;
	act = pile;
	while (act->next)
	{
		if (act->nb < lower->nb)
			lower = act;
		act = act->next;
	}
	if (act->nb < lower->nb)
		lower = act;
	return (lower);
}

t_pile	*get_upper(t_pile *pile)
{
	t_pile	*act;
	t_pile	*upper;

	upper = pile;
	act = pile;
	while (act->next && act->next != pile)
	{
		if (act->nb > upper->nb)
			upper = act;
		act = act->next;
	}
	if (act->nb > upper->nb)
		upper = act;
	return (upper);
}

t_pile *new_pile_node(int value)
{
	t_pile *new;

	new = (t_pile *)malloc(sizeof (t_pile));
	if (!new)
		return (NULL);
	new->nb = value;
	new->next = NULL;
	new->prev = NULL;
	new->target = NULL; 
	return (new);
}

t_pile *pile_last(t_pile *pile)
{
	t_pile *last;

	last = pile;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

void	pile_add_back(t_pile **pile, t_pile *new)
{
	t_pile	*last_node;

	if (!*pile)
	{
		new->next = NULL;
		new->prev = NULL;
		*pile = new;
	}
	else
	{
		last_node = pile_last(*pile);
		new->prev = last_node;
		last_node->next = new;
		new->next = NULL;
	}
}

void	pile_add_front(t_pile **pile, t_pile *new)
{
	if (*pile == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*pile = new;
	}
	else
	{
		new->prev = NULL;
		(*pile)->prev = new;
		new->next = *pile;
		*pile = new;
	}
}

int	pile_size(t_pile *pile)
{
	int     i;
	t_pile  *node;

	if (pile == NULL)
		return (0);
	i = 0;
	node = pile;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}