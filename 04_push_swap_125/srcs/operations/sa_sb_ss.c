/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:24:54 by layang            #+#    #+#             */
/*   Updated: 2025/01/23 13:49:08 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_swap(t_list	**stack)
{
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_list	**a)
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list	**b)
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list	**a, t_list	**b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
}
