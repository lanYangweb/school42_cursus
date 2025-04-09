/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:38:24 by layang            #+#    #+#             */
/*   Updated: 2025/01/23 13:57:20 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

// main functions
int		ft_atoi_ctl(const char	*str);
t_list	*put_a(char	**av);
int		instruct(char	*input, t_stack	*tab);
int		is_sorted_a(t_list	*a);
void	checker(t_stack	**tab, char	**av, int nb, int ac);

// operations
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

#endif