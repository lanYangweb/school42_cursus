/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:04:14 by layang            #+#    #+#             */
/*   Updated: 2025/01/23 13:48:22 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;
}	t_stack;

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_push;

//main function used in put_a_index.c
int		ft_atoi_ctl(const char *str);

//operations
void	sa(t_list	**a);
void	sb(t_list	**b);
void	ss(t_list	**a, t_list	**b);
void	pa(t_list	**a, t_list	**b);
void	pb(t_list	**a, t_list	**b);
void	ra(t_list	**a);
void	rb(t_list	**b);
void	rr(t_list	**a, t_list	**b);
void	rra(t_list	**a);
void	rrb(t_list	**b);
void	rrr(t_list	**a, t_list	**b);

// index stack, free stacks, and sorting
int		find_max_index(t_list	**lst);
void	index_a(t_list	*a, int len);
t_list	*put_a(char	**av);
void	free_stacks(t_stack	**t);
int		is_sorted(t_list	**t);
int		is_sorted_a(t_list	**a, int nb);
void	sort_2_or_3_nbr(t_stack	*tab, int nb);
void	sort_5_nbr(t_stack	*tab, int nb);
void	quick_sort(t_list	**a, t_list	**b, int nb);

#endif