/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:18:17 by layang            #+#    #+#             */
/*   Updated: 2025/01/23 13:54:36 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	ft_rotate(t_list	**stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = (*stack)->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

void	ra(t_list	**a)
{
	ft_rotate(a);
}

void	rb(t_list	**b)
{
	ft_rotate(b);
}

void	rr(t_list	**a, t_list	**b)
{
	ft_rotate(a);
	ft_rotate(b);
}
