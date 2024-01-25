/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:16:24 by tgibert           #+#    #+#             */
/*   Updated: 2024/01/24 06:32:04 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_pile	*get_by_index(t_pile *pile, int index)
{
	t_pile	*node;

	if (index = 0)
		return (pile);
	node = pile->next;
	while (index--)
		node = node->next;
	return (node);
}

int	get_target(int nb, t_pile *pile)
{
	int	index;
	int	lowst_grtr_vlue;
	t_pile	*act;

	index = 0;
	lowst_grtr_vlue = INT_MAX;
	if (pile->nb > nb)
		lowst_grtr_vlue = nb;
	act = pile->next;
	while (act != pile)
	{
		if (act->nb > nb && act->nb < lowst_grtr_vlue)
			lowst_grtr_vlue = nb;
		act = act->next;
	}
	if (lowst_grtr_vlue == INT_MAX)
		return (get_index(pile, get_lower(pile)));
	return (get_index(pile, lowst_grtr_vlue));
}

void	set_lst_target(t_ab *ab)
{
	t_pile	*act;

	ab->pile_b->trgt_i = get_target(ab->pile_b->nb, ab->pile_a);
	act = ab->pile_b->next;
	while (act && act != ab->pile_b)
	{
		act->trgt_i = get_target(act->nb, ab->pile_a);
		act = act->next;
	}
}

void	set_cost(t_pile *node_b, t_pile *pile_a)
{
	int	cost_indx;
	int	trgt_cost;
	int	len_a;
	int	len_b;

	len_b = pile_size(node_b);
	len_a = pile_size(pile_a);
	node_b->cost = node_b->index;
	if (node_b->index > len_b / 2)
		node_b->cost = len_b - node_b->index;
	if (node_b->trgt_i > len_a / 2)
		node_b->cost += len_a - node_b->trgt_i;
	else
		node_b->cost += node_b->trgt_i;
}

void	set_lst_cost(t_ab *ab)
{
	int		cost;
	t_pile	*act;

	cost = 0;
	ab->pile_b->cost = get_cost(ab->pile_b, ab->pile_a);
	act = ab->pile_b->next;
	while (act && act != ab->pile_b)
	{
		act->cost = get_cost(act, ab->pile_a);
		act = act->next;
	}
}

void	set_index(t_pile *pile)
{
	t_pile	*act;
	int	index;

	pile->index = 0;
	index = 1;
	act = pile->next;
	while (act != pile)
	{
		act->index = index;
		act = act->next;
		index++;
	}
}

t_pile	*get_lower_cost(t_pile *pile)
{
	int	lower;
	t_pile	*act;
	t_pile	*lower_node;

	lower = pile->cost;
	lower_node = pile;
	act = pile->next;
	while (act != pile)
	{
		if (act->cost < lower)
		{
			lower_node = act;
			lower = act->cost;
		}
		act = act->next;
	}
	return (lower_node);
}

int	same_dir(t_ab *ab, t_pile *lower, t_pile *target)
{
	if (lower->index > pile_size(ab->pile_b) / 2 && lower->trgt_i > pile_size(ab->pile_a) / 2)
		return (-1);
	if (lower->index < pile_size(ab->pile_b) / 2 && lower->trgt_i < pile_size(ab->pile_a) / 2)
		return (1);
	return (0);
}

void	combine_rotates(t_ab *ab, t_pile *lower, t_pile *target)
{
	int	i;

	i = lower->index - lower->trgt_i;
	if (i < 0)
		i = -i;
	rrn(ab, i);
}

void	combine_r_rotates(t_ab *ab, t_pile *lower, t_pile *target)
{
	int	i;

	i = (pile_size(lower) - lower->index) - (pile_size(target) - lower->trgt_i);
	if (i < 0)
		i = -i;
	rrrn(ab, i);
}

void	get_on_top(t_ab *ab, t_pile **pile, t_pile *target)
{
	int	dir;

	if (target->index > pile_size(target) / 2)
		dir = 1;
	else
		dir = -1;
	if (dir == 1)
		while (*pile != target)
			ra(ab);
	else
		while (*pile != target)
			rra(ab);
}

void	get_targets_on_top(t_ab *ab, t_pile *lower, t_pile *target)
{
	get_on_top(ab, &ab->pile_a, target);
	get_on_top(ab, &ab->pile_b, lower);
}

void	push_low_cost(t_ab *ab)
{
	t_pile	*lower;
	t_pile	*target;

	lower = get_lower_cost(ab->pile_b);
	target = get_by_index(ab->pile_a, lower->trgt_i);
	if (same_dir(ab, lower, target) == 1)
		combine_rotates(ab, lower, target);
	else if (same_dir(ab, lower, target) == -1)
		combine_r_rotates(ab, lower, target);
	get_targets_on_top(ab, lower, target);
	pa(ab);
}

void	sort_long_new(t_ab *ab)
{
	while (pile_size(ab->pile_a) > 3)
		pb(ab);
	sort_three(ab);
	while (ab->pile_b)
	{
		set_lst_target(ab);
		set_lst_cost(ab);
		push_low_cost(ab);
	}
}

void	destroy_pile(t_pile **pile)
{
	t_pile *act;
	t_pile *next;

	act = (*pile)->next;
	while (act != *pile)
	{
		next = act->next;
		free(act);
		act = next;
	}
	free(act);
	*pile = NULL;
}

void	clean(t_ab *ab)
{
	destroy_pile(&(ab->pile_a));
}

int	main(int ac, char *av[])
{
	t_ab		ab;
	t_instructs	*instructs;

	ab.pile_b = NULL;
	if (ac < 2)
	{
		/* instructs = read_stdin();
		ab.pile_a = create_first_pile(instructs->nb, instructs->instructs); */
		ft_perror("Error\nPlease enter number to sort\n");
		return(0);
	}
	else
		ab.pile_a = create_first_pile(av + 1);
	//push(&pile_a, &pile_b);
	if (pile_size(ab.pile_a) <= 10)
		resolve_small(&ab);
	else
		sort_long_new(&ab);
	// print_piles(ab);
	// sort_three(&ab);
	// print_piles(ab);
	// clean(&ab);
	return (0);
}
