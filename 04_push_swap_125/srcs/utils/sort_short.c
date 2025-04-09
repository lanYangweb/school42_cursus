/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:09:55 by layang            #+#    #+#             */
/*   Updated: 2025/01/23 13:51:43 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_stacks(t_stack	**t)
{
	t_list	*tmp;
	t_list	*next;

	tmp = (*t)->a;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	tmp = (*t)->b;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*t);
}

int	is_sorted(t_list	**t)
{
	t_list	*tmp;

	tmp = *t;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_sorted_a(t_list	**a, int nb)
{
	int	len;

	len = ft_lstsize(*a);
	if (len != nb || !is_sorted(a))
		return (0);
	return (1);
}

/* void	sort_2_or_3_nbr(t_stack *tab, int nb)
{
	if (nb == 2)
	{
		if (tab->a->content > tab->a->next->content)
			sa(&tab->a);
	}
	if (nb == 3)
	{
		if (tab->a->index == 1 && tab->a->next->index == 0)
			sa(&tab->a);
		else if (tab->a->index == 1 && tab->a->next->index == 2)
			rra(&tab->a);
		else if (tab->a->index == 2 && tab->a->next->index == 0)
			ra(&tab->a);
		else if (tab->a->index == 2 && tab->a->next->index == 1)
		{
			sa(&tab->a);
			rra(&tab->a);
		}
		else if (tab->a->index == 0 && tab->a->next->index == 2)
		{
			rra(&tab->a);
			sa(&tab->a);
		}
	}
} */

void	sort_2_or_3_nbr(t_stack	*tab, int nb)
{
	int	nbr;

	if (nb == 2)
	{
		if (tab->a->content > tab->a->next->content)
			sa(&tab->a);
	}
	if (nb == 3 && !is_sorted(&tab->a))
	{
		nbr = tab->a->index + tab->a->next->index;
		if (nbr == 1 || nbr == 5)
			sa(&tab->a);
		else if (nbr == 3 || nbr == 7)
		{
			if (tab->a->index > tab->a->next->index)
				sa(&tab->a);
			rra(&tab->a);
		}
		else if (nbr == 2 || nbr == 6)
		{
			if (tab->a->index < tab->a->next->index)
				sa(&tab->a);
			ra(&tab->a);
		}
	}
}

void	sort_5_nbr(t_stack	*tab, int nb)
{
	while (nb--)
	{
		if (tab->a->index == 0 || tab->a->index == 1)
			pb(&tab->a, &tab->b);
		else
			ra(&tab->a);
	}
	sort_2_or_3_nbr(tab, 3);
	if (tab->b->index == 0)
		sb(&tab->b);
	pa(&tab->a, &tab->b);
	pa(&tab->a, &tab->b);
}
