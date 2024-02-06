/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:01:12 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/06 15:44:39 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss(t_ab *ab)
{
    ft_printf("ss\n");
    swap(&(ab->pile_a));
    swap(&(ab->pile_b));
}

void    rr(t_ab *ab)
{
    ft_printf("rr\n");
    rotate(&(ab->pile_a));
    rotate(&(ab->pile_b));
}

void    rrr(t_ab *ab)
{
    ft_printf("rrr\n");
    reverse_rotate(&(ab->pile_a));
    reverse_rotate(&(ab->pile_b));
}