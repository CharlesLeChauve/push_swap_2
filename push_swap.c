/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:09:49 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/07 07:21:58 by tgibert          ###   ########.fr       */
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
}

void	set_indexes(t_ab *ab)
{
	t_pile *act;
	int		index;

	act = ab->pile_a;
	index = 0;
	while (act)
	{
		act->index = index;
		act = act->next;
		index++;
	}
	index = 0;
	act = ab->pile_b;
	while (act)
	{
		act->index = index;
		act = act->next;
		index++;
	}
}

void	set_costs(t_ab *ab)
{
	int		size;
	t_pile	*act;

	size = pile_size(ab->pile_a);
	act = ab->pile_a;
	while (act)
	{
		if (act->index <= size / 2)
			act->cost = act->index;
		else
			act->cost = size - act->index;
		act = act->next;
	}
	size = pile_size(ab->pile_b);
	act = ab->pile_b;
	while (act)
	{
		if (act->index <= size / 2)
			act->cost = act->index;
		else
			act->cost = size - act->index;
		act = act->next;
	}
}

t_pile	*get_min_node(t_pile *pile)
{
	t_pile	*act;
	t_pile	*min;

	act = pile;
	min = act;
	while (act)
	{
		if (act->nb < min->nb)
			min = act;
		act = act->next;
	}
	return (min);
}

void	set_node_target(t_pile *node, t_pile *pile_a)
{
	int		lwst_grtr_vlue;
	t_pile	*act;
	t_pile	*target;

	lwst_grtr_vlue = INT_MAX;
	act = pile_a;
	while (act)
	{
		if (act->nb > node->nb && act->nb < lwst_grtr_vlue)
		{
			lwst_grtr_vlue = act->nb;
			target = act;
		}
		act = act->next;
	}
	if (lwst_grtr_vlue == INT_MAX)
	{
		target = get_min_node(pile_a);
	}
	node->target = target;
}

void	set_targets(t_ab *ab)
{
	t_pile	*node;

	node = ab->pile_b;
	while (node)
	{
		set_node_target(node, ab->pile_a);
		node = node->next;
	}
}

int		total_cost(t_pile *node)
{
	return (node->cost + node->target->cost);
}

t_pile	*get_cheapest(t_ab *ab)
{
	t_pile	*cheapest;
	t_pile	*act;
	int		lower_cost;

	act = ab->pile_b;
	cheapest = act;
	lower_cost = total_cost(act);
	while (act)
	{
		if (total_cost(act) < lower_cost)
		{
			cheapest = act;
			lower_cost = total_cost(act);
		}
		act = act->next;
	}
	return (cheapest);
}

void	get_on_top_a(t_ab *ab, t_pile *target)
{
	int		dir;
	t_pile	**pile;

	pile = &(ab->pile_a);
	if (target->index <= pile_size(*pile) / 2)
		dir = 1;
	else
		dir = -1;
	if (dir == 1)
		ran(ab, target->cost);
	else
		rran(ab, target->cost);
}

void	get_on_top_b(t_ab *ab, t_pile *target)
{
	int		dir;
	t_pile	**pile;

	pile = &(ab->pile_b);
	if (target->index <= pile_size(*pile) / 2)
		dir = 1;
	else
		dir = -1;
	if (dir == 1)
		rbn(ab, target->cost);
	else
		rrbn(ab, target->cost);
}

int	get_dir(t_pile *pile, t_pile *node)
{
	int	size;

	size = pile_size(pile);
	if (node->index <= size / 2)
		return (1);
	else 
		return (-1);
}

void	combine_rotates(t_ab *ab, t_pile *cheapest, t_pile *target)
{
	int	i;
	int	max;
	int	diff;
	
	if (cheapest->cost == 0 || target->cost == 0)
		return;
	diff = target->cost - cheapest->cost;
	if (diff < 0)
		diff = -diff;
	if (target->cost > cheapest->cost)
		max = target->cost;
	else
		max = cheapest->cost;
	i = max - diff;
	rrn(ab, i);
	target->cost -= i;
	cheapest->cost -= i;
}

void	combine_r_rotates(t_ab *ab, t_pile *cheapest, t_pile *target)
{
	int	i;
	int	max;
	int	diff;
	
	if (cheapest->cost == 0 || target->cost == 0)
		return;
	diff = target->cost - cheapest->cost;
	if (diff < 0)
		diff = -diff;
	if (target->cost > cheapest->cost)
		max = target->cost;
	else
		max = cheapest->cost;
	i = max - diff;
	rrrn(ab, i);
	target->cost -= i;
	cheapest->cost -= i;
}

void	get_targets_on_top(t_ab *ab, t_pile *cheapest, t_pile *target)
{
	int a_dir;
	int	b_dir;

	a_dir = get_dir(ab->pile_a, target);
	b_dir = get_dir(ab->pile_b, cheapest);
	if (a_dir == b_dir && a_dir == 1)
		combine_rotates(ab, cheapest, target);
	else if (a_dir == b_dir && a_dir == -1)
		combine_r_rotates(ab, cheapest, target);
	get_on_top_a(ab, target);
	get_on_top_b(ab, cheapest);
}

void	get_min_on_top(t_ab *ab)
{
	t_pile *min;

	min = get_lower(ab->pile_a);
	set_indexes(ab);
	if (min->index <= pile_size(ab->pile_a) / 2)
		ran(ab, min->index);
	else
		rran(ab, pile_size(ab->pile_a) - min->index);
}

void	sort_long(t_ab *ab)
{
	t_pile	*cheapest;

	while (pile_size(ab->pile_a) > 3)
		pb(ab);
	sort_three(ab);
	while (ab->pile_b)
	{
		set_indexes(ab);
		set_targets(ab);
		set_costs(ab);
		//print_piles(*ab);
		cheapest = get_cheapest(ab);
		//printf("cheapest = %d, index = %d, cost = %d, target = %d, target cost = %d, total cost = %d\n",
		//	cheapest->nb, cheapest->index, cheapest->cost, cheapest->target->nb, cheapest->target->cost,  cheapest->target->cost + cheapest->cost);
		get_targets_on_top(ab, cheapest, cheapest->target);
		pa(ab);
	}
	get_min_on_top(ab);
}

int	main(int ac, char *av[])
{
	t_ab		ab;

	ab.pile_b = NULL;
	if (ac < 2)
	{
		ft_perror("Error\nPlease enter number to sort\n");
		return(0);
	}
	else
		ab.pile_a = create_first_pile(av + 1);
	resolve_small(&ab);
	sort_long(&ab);
	return (0);
}