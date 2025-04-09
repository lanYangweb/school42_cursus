/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:10:24 by layang            #+#    #+#             */
/*   Updated: 2025/01/23 13:51:07 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	first_push(t_list	**a, t_list	**b, t_push *push, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if ((*a)->index <= push->mid)
			pb(a, b);
		else
		{
			if (ft_lstsize(*b) > 1 && (*b)->index < (push->mid / 2))
				rr(a, b);
			else
				ra(a);
		}
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

static void	find_next(t_list	**a, t_list	**b, t_push	*push)
{
	if (ft_lstsize(*b) > 0 && ((*b)->index == push->next))
		pa(a, b);
	else if ((*a)->index == push->next)
	{
		(*a)->flag = -1;
		ra(a);
		push->next++;
	}
	else if ((ft_lstsize(*b)) > 2 && ft_lstlast(*b)->index == push->next)
		rrb(b);
	else if ((*a)->next->index == push->next)
		sa(a);
	else if ((ft_lstsize(*a)) > 1 && ((*a)->next->index == push->next)
		&& ((*b)->next->index == push->next + 1))
		ss(a, b);
	else
		return ;
	find_next(a, b, push);
}

static void	quick_a(t_list	**a, t_list	**b, t_push	*push)
{
	int	count_b;
	int	i;

	i = -1;
	count_b = ft_lstsize(*b);
	while (ft_lstsize(*b) && ++i < count_b)
	{
		if ((*b)->index == push->next)
			find_next(a, b, push);
		else if ((*b)->index >= push->mid)
		{
			(*b)->flag = push->flag;
			pa(a, b);
		}
		else if ((*b)->index < push->mid)
			rb(b);
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

static void	quick_b(t_list	**a, t_list	**b, t_push	*push)
{
	int	cur_flag;

	cur_flag = (*a)->flag;
	if ((*a)->flag != 0)
	{
		while ((*a)->flag == cur_flag)
		{
			if ((*a)->index != push->next)
				pb(a, b);
			find_next(a, b, push);
		}
	}
	else if ((*a)->flag == 0)
	{
		while ((*a)->flag != -1)
		{
			if ((*a)->index != push->next)
				pb(a, b);
			find_next(a, b, push);
		}
	}
	if (ft_lstsize(*b))
		push->max = find_max_index(b);
	push->mid = (push->max - push->next) / 2 + push->next;
}

void	quick_sort(t_list	**a, t_list	**b, int nb)
{
	t_push	push;

	push.next = 0;
	push.max = nb - 1;
	push.mid = push.max / 2 + push.next;
	push.flag = 0;
	first_push(a, b, &push, nb);
	while (!is_sorted_a(a, nb))
	{
		if (ft_lstsize(*b) == 0)
			quick_b(a, b, &push);
		else
			quick_a(a, b, &push);
	}
}
