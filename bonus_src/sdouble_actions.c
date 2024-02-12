/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdouble_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:01:12 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/07 13:47:12 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sss(t_ab *ab)
{
    swap(&(ab->pile_a));
    swap(&(ab->pile_b));
}

void    srr(t_ab *ab)
{
    rotate(&(ab->pile_a));
    rotate(&(ab->pile_b));
}

void    srrr(t_ab *ab)
{
    reverse_rotate(&(ab->pile_a));
    reverse_rotate(&(ab->pile_b));
}