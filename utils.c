/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:40:18 by tgibert           #+#    #+#             */
/*   Updated: 2024/01/24 17:18:53 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_above_nb(t_pile *pile, int med)
{
	int		nb;
	t_pile	*act;

	act = pile->next;
	nb = get_upper(pile);
	while (act != pile)
	{
		if (act->nb > med && act->nb < nb)
			nb = act->nb;
		act = act->next;
	}
	if (act->nb > med && act->nb < nb)
			nb = act->nb;
	return (nb);
}

int	get_below_nb(t_pile *pile, int med)
{
	int		nb;
	t_pile	*act;

	act = pile->next;
	nb = get_lower(pile);
	while (act != pile)
	{
		if (act->nb < med && act->nb > nb)
			nb = act->nb;
		act = act->next;
	}
	if (act->nb < med && act->nb > nb)
			nb = act->nb;
	return (nb);
}

t_pile	*get_by_index(t_pile *pile, int index)
{
	t_pile	*node;

	if (index == 0)
		return (pile);
	node = pile->next;
	while (index--)
		node = node->next;
	return (node);
}


int		get_index(t_pile *pile, int nb)
{
	t_pile *act;
	int		index;

	if (!pile)
		return (-1);
	if (pile->nb == nb)
		return (0);
	index = 1;
	act = pile->next;
	while (act != pile)
	{
		if (act->nb == nb)
			return (index);
		act = act->next;
		index++;
	}
	return (-2);
}

int		get_lower(t_pile *pile)
{
	int 	min;
	t_pile	*act;

	min = pile->nb;
	act = pile;
	if (pile->prev->nb < pile->nb)
		min = pile->prev->nb;
	while (act->next != pile)
	{
		if (act->nb < min)
			min = act->nb;
		act = act->next;
	}
	return (min);
}

int	get_upper(t_pile *pile)
{
	int 	max;
	t_pile	*act;

	max = pile->nb;
	act = pile;
	if (pile->prev->nb > pile->nb)
		max = pile->prev->nb;
	while (act->next != pile)
	{
		if (act->nb > max)
			max = act->nb;
		act = act->next;
	}
	return (max);
}

int	is_sorted(t_pile *pile)
{
	t_pile	*act;

	act = pile->next;
	while (act != pile)
	{
		if (act->nb < act->prev->nb)
			return(0);
		act = act->next;
	}
	return(1);
}

t_pile	*new_pile_node(int value)
{
	t_pile *new;

	new = (t_pile *)malloc(sizeof (t_pile));
	if (!new)
		return (NULL);
	new->nb = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void    pile_add_front(t_pile **lst, t_pile *new)
{
	t_pile  *first;
	
	if (*lst != NULL)
	{
		first = *lst;
		new->prev = first->prev;
		first->prev->next = new;
		first->prev = new;
		new->next = first;
		*lst = new;
	}
	else
	{
		*lst = new;
		new->prev = new;
		new->next = new;
	}
}

void	pile_add_back(t_pile **lst, t_pile *new)
{
	t_pile	*last_node;

	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last_node = *lst;
		while (last_node->next && last_node->next != *lst)
			last_node = last_node->next;
		new->prev = last_node;
		new->next = *lst;
		last_node->next = new;
		(*lst)->prev = new;
	}
}

t_pile *pile_last(t_pile *pile)
{
	t_pile *last;

	last = pile;
	while (last->next != pile)
	{
		last = last->next;
	}
	return (last);
}

int pile_size(t_pile *pile)
{
	int     i;
	t_pile  *node;

	if (pile == NULL)
		return (0);
	i = 1;
	node = pile;
	while (node->next != pile)
	{
		node = node->next;
		i++;
	}
	return (i);
}
