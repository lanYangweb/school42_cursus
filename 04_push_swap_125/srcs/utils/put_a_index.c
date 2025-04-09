/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_a_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:35:41 by layang            #+#    #+#             */
/*   Updated: 2025/01/23 13:50:07 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_max_index(t_list	**lst)
{
	t_list	*tmp;
	int		max_index;

	tmp = *lst;
	max_index = tmp->index;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

static int	min_nbr(t_list	*a)
{
	t_list	*tmp;
	int		min;

	tmp = a;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->index == -1)
		{
			min = tmp->content;
			break ;
		}
		else
			tmp = tmp->next;
	}
	tmp = a;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

static void	put_index(t_list	*a, int min, int index)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->content == min)
			break ;
		tmp = tmp->next;
	}
	if (tmp != NULL)
		tmp->index = index;
}

void	index_a(t_list	*a, int len)
{
	int	i;
	int	min;

	i = 0;
	while (i < len)
	{
		min = min_nbr(a);
		put_index(a, min, i);
		i++;
	}
}

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
