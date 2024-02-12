/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:42:46 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/07 08:30:28 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sa(t_ab *ab)
{
	ft_printf("sa\n");
	swap(&(ab->pile_a));
}

void    ra(t_ab *ab)
{
	ft_printf("ra\n");
	rotate(&(ab->pile_a));
}

void    rra(t_ab *ab)
{
	ft_printf("rra\n");
	reverse_rotate(&(ab->pile_a));
}

void    pa(t_ab *ab)
{
	ft_printf("pa\n");
	push(&ab->pile_b, &ab->pile_a);
}