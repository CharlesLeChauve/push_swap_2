/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:42:46 by tgibert           #+#    #+#             */
/*   Updated: 2024/02/07 13:46:32 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ssa(t_ab *ab)
{
	swap(&(ab->pile_a));
}

void    sra(t_ab *ab)
{
	rotate(&(ab->pile_a));
}

void    srra(t_ab *ab)
{
	reverse_rotate(&(ab->pile_a));
}

void    spa(t_ab *ab)
{
	push(&ab->pile_b, &ab->pile_a);
}