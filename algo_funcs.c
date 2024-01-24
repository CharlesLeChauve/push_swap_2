/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:20:02 by tgibert           #+#    #+#             */
/*   Updated: 2024/01/23 06:37:56 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_cresc_a_swap(t_ab *ab);
void	check_decresc_a_swap(t_ab *ab);

int	forward_closer(int	median, t_ab *ab)
{
	int	i;
	t_pile	*pile;

	pile = ab->pile_a;
	if (pile->nb < median)
		return (0);
	i = 1;
	pile = pile->next;
	while (pile != ab->pile_a)
	{
		if (pile->nb < median)
			return (i);
		i++;
		pile = pile->next;
	}
	return (0);
}

int	backward_closer(int	median, t_ab *ab)
{
	int	i;
	t_pile	*pile;

	pile = ab->pile_a;
	if (pile->nb < median)
		return (0);
	i = 1;
	pile = pile->prev;
	while (pile != ab->pile_a)
	{
		if (pile->nb < median)
			return (i);
		pile = pile->prev;
		i++;
	}
	return (0);
}

void	get_forward(int	index, t_ab *ab)
{
	int	i;

	i = 0;
	while (i < index)
	{
		//check_cresc_a_swap(ab);
		ra(ab);
		i++;
	}
}

void	get_backward(int rev_index, t_ab *ab)
{
	int	i;

	i = rev_index;
	while (i > 0)
	{
		//check_decresc_a_swap(ab);
		rra(ab);
		i--;
	}
}

void	check_cresc_a_swap(t_ab *ab)
{
	if (ab->pile_a->nb < ab->pile_a->next->nb/*  && ab->pile_a->nb > ab->pile_a->prev->nb */)
		sa(ab);
}

void	check_decresc_a_swap(t_ab *ab)
{
	if (ab->pile_a->nb > ab->pile_a->next->nb && ab->pile_a->nb > ab->pile_a->prev->nb)
		sa(ab);
}

void	push_min_to_b(t_ab *ab)
{
	int	index;
	int	size;

	index = get_index(ab->pile_a, get_lower(ab->pile_a));
	size = pile_size(ab->pile_a);
	if (index <= size / 2)
		ran(ab, index);
	else
		rran(ab, size - index);
	pb(ab);
}
 
void	push_max_to_a(t_ab *ab)
{
	int	index;
	int	size;

	index = get_index(ab->pile_b, get_upper(ab->pile_b));
	size = pile_size(ab->pile_b);
	//printf("Index = %d, size = %d\n", get_index(ab->pile_a, get_lower(ab->pile_a)), size);
	if (index <= size / 2)
		rbn(ab, index);
	else
		rrbn(ab, size - index);
	pa(ab);
	//print_piles(*ab);
}
void	find_closer_under_param(int median, t_ab *ab)
{
	int	f;
	int	b;

	f = forward_closer(median, ab);
	b = backward_closer(median, ab);
	if (f < b)
		get_forward(f, ab);
	else
		get_backward(b, ab);
}

void	split_chunks(int median, int size, t_ab *ab)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		find_closer_under_param(median, ab);
		pb(ab);
		i++;
	}
}

int	find_forth_max(t_ab *ab)
{
	int		index;
	int		i;
	t_pile	*act;

	index = pile_size(ab->pile_a) - 3;
	i = 0;
	act = cheat_sort(ab->pile_a);
	while (i < index)
	{
		act = act->next;
		i++;
	}
	return (act->nb);
}

void	push_forth_max(t_ab *ab)
{
	int	nb;
	int	index;
	int	size;

	nb = find_forth_max(ab);
	index = get_index(ab->pile_a, nb);
	size = pile_size(ab->pile_a);
	if (index <= size / 2)
	{
		while (index != 0)
		{
			ra(ab);
			index--;
		}
	}
	else
	{
		while (index < size)
		{
			rra(ab);
			index++;
		}
	}
	pb(ab);	
}