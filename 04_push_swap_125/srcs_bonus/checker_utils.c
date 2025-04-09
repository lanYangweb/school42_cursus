/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:39:08 by layang            #+#    #+#             */
/*   Updated: 2025/01/25 15:36:35 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*put_a(char	**av)
{
	t_list	*t;
	t_list	*res;
	int		i;

	i = 0;
	res = NULL;
	while (av[i])
	{
		t = ft_lstnew(ft_atoi_ctl(av[i]));
		ft_lstadd_back(&res, t);
		t->index = -1;
		i++;
	}
	return (res);
}

int	is_sorted_a(t_list	*stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/* int	instruct(char	*input, t_stack	*tab)
{
	if (ft_strncmp(input, "sa\n", 2) == 0)
		sa(&tab->a);
	else if (ft_strncmp(input, "sb\n", 2) == 0)
		sb(&tab->b);
	else if (ft_strncmp(input, "ss\n", 2) == 0)
		ss(&tab->a, &tab->b);
	else if (ft_strncmp(input, "pa\n", 2) == 0)
		pa(&tab->a, &tab->b);
	else if (ft_strncmp(input, "pb\n", 2) == 0)
		pb(&tab->a, &tab->b);
	else if (ft_strncmp(input, "ra\n", 2) == 0)
		ra(&tab->a);
	else if (ft_strncmp(input, "rb\n", 2) == 0)
		rb(&tab->b);
	else if (ft_strncmp(input, "rra\n", 3) == 0)
		rra(&tab->a);
	else if (ft_strncmp(input, "rrb\n", 3) == 0)
		rrb(&tab->b);
	else
	{
		free(input);
		return (0);
	}
	free(input);
	return (1);
} rrr and rr missed */

static void	instruct_rr(char *input, t_stack *tab)
{
	if (ft_strncmp(input, "rr\n", 3) == 0)
		rr(&tab->a, &tab->b);
	else if (ft_strncmp(input, "rra\n", 4) == 0)
		rra(&tab->a);
	else if (ft_strncmp(input, "rrb\n", 4) == 0)
		rrb(&tab->b);
	else if (ft_strncmp(input, "rrr\n", 4) == 0)
		rrr(&tab->a, &tab->b);
}

int	instruct(char	*input, t_stack	*tab)
{
	if (ft_strncmp(input, "sa\n", 3) == 0)
		sa(&tab->a);
	else if (ft_strncmp(input, "sb\n", 3) == 0)
		sb(&tab->b);
	else if (ft_strncmp(input, "ss\n", 3) == 0)
		ss(&tab->a, &tab->b);
	else if (ft_strncmp(input, "pa\n", 3) == 0)
		pa(&tab->a, &tab->b);
	else if (ft_strncmp(input, "pb\n", 3) == 0)
		pb(&tab->a, &tab->b);
	else if (ft_strncmp(input, "ra\n", 3) == 0)
		ra(&tab->a);
	else if (ft_strncmp(input, "rb\n", 3) == 0)
		rb(&tab->b);
	else if (!ft_strncmp(input, "rr\n", 3) || !ft_strncmp(input, "rra\n", 4)
		|| !ft_strncmp(input, "rrb\n", 4) || !ft_strncmp(input, "rrr\n", 4))
		instruct_rr(input, tab);
	else
	{
		free(input);
		return (0);
	}
	free(input);
	return (1);
}
