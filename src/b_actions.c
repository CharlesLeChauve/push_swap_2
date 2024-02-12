/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:58:14 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/07 13:44:02 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sb(t_ab *ab)
{
	ft_printf("sb\n");
	swap(&(ab->pile_b));
}

void    rb(t_ab *ab)
{
	ft_printf("rb\n");
	rotate(&(ab->pile_b));
}

void    rrb(t_ab *ab)
{
	ft_printf("rrb\n");
	reverse_rotate(&(ab->pile_b));
}

void    pb(t_ab *ab)
{
	ft_printf("pb\n");
	push(&ab->pile_a, &ab->pile_b);
}