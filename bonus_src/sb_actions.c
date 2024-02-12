/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:58:14 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/07 13:46:56 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ssb(t_ab *ab)
{
	swap(&(ab->pile_b));
}

void    srb(t_ab *ab)
{
	rotate(&(ab->pile_b));
}

void    srrb(t_ab *ab)
{
	reverse_rotate(&(ab->pile_b));
}

void    spb(t_ab *ab)
{
	push(&ab->pile_a, &ab->pile_b);
}