/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:01:31 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 12:09:13 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Frees the memory of the node’s content and frees the node itself.
*/
void	ft_lstdelone(t_list	*lst, void (*del)(void	*))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}
