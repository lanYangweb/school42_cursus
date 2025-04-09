/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:00:13 by layang            #+#    #+#             */
/*   Updated: 2025/01/23 13:49:18 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_push(t_list	**stack1, t_list	**stack2)
{
	t_list	*push;

	if (!*stack2)
		return ;
	push = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = push;
}

void	pa(t_list	**a, t_list	**b)
{
	ft_push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list	**a, t_list	**b)
{
	ft_push(b, a);
	ft_putstr_fd("pb\n", 1);
}
