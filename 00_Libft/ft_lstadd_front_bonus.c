/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:01:21 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 12:08:36 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Adds the node new at the beginning of the list.
*/
void	ft_lstadd_front(t_list	**lst, t_list	*new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
