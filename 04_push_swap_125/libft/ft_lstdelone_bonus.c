/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:01:31 by layang            #+#    #+#             */
/*   Updated: 2025/01/18 13:48:50 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Frees the memory of the node’s content and frees the node itself.
*/
void	ft_lstdelone(t_list	*lst, void (*del)(int))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}
