/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibert <tgibert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:49:35 by tgibert           #+#    #+#             */
/*   Updated: 2024/01/24 17:22:03 by tgibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

# define INT_MAX 2147483647

typedef struct s_cheapest
{
	int	value;
	int	nb_inst;
	int	a_index;
	int	b_index;
}		t_cheapest;

typedef struct s_instructs
{
	char	**instructs;
	int	nb;
}		t_instructs;

typedef	struct	s_meds
{
	int	hi;
	int	lo;
}		t_meds;

typedef struct s_pile
{
	int		nb;
	int		index;
	int		trgt_i;
	int		cost;
	struct s_pile	*next;
	struct s_pile	*prev;
}			t_pile;

typedef struct s_ab
{
	t_pile	*pile_a;
	t_pile	*pile_b;
}			t_ab;

void    sa(t_ab *ab);
void    ra(t_ab *ab);
void    rra(t_ab *ab);
void    pa(t_ab *ab);
void    sb(t_ab *ab);
void    rb(t_ab *ab);
void    rrb(t_ab *ab);
void    pb(t_ab *ab);
void    ss(t_ab *ab);
void    rr(t_ab *ab);
void    rrr(t_ab *ab);

void	ft_perror(char *str);
void	print_piles(t_ab ab);
void	print_pile(t_pile *pile);

int	get_index(t_pile *pile, int nb);
int	get_lower(t_pile *pile);
int	get_upper(t_pile *pile);
int	get_median(t_pile *pile);
int	get_nthile(t_pile *pile, int n);
void	set_index(t_pile *pile);
int	is_sorted(t_pile *pile);
t_pile	*get_by_index(t_pile *pile, int index);

void	rotate(t_pile **pile);
void	reverse_rotate(t_pile **pile);
void	swap(t_pile **pile);
void	push(t_pile **src, t_pile **dst);

t_pile	*pile_last(t_pile *pile);
t_pile	*new_pile_node(int value);
t_pile	*cheat_sort(t_pile *src_pile);
void	pile_add_front(t_pile **lst, t_pile *new);
void	pile_add_back(t_pile **lst, t_pile *new);
int		pile_size(t_pile *pile);

void	resolve_small(t_ab *ab);

void	push_forth_max(t_ab *ab);
void	split_chunks(int median, int size, t_ab *ab);
void	check_swap(t_ab *ab);

t_pile	*create_first_pile(char **av);
void	push_min_to_b(t_ab *ab);
void	push_max_to_a(t_ab *ab);
void	sort_three(t_ab *ab);

void	destroy_pile(t_pile **pile);

void	rran(t_ab *ab, int n);
void	ran(t_ab *ab, int n);
void	rrbn(t_ab *ab, int n);
void	rbn(t_ab *ab, int n);
void	rrn(t_ab *ab, int n);
void	rrrn(t_ab *ab, int n);

#endif //PUSH_SWAP_H
