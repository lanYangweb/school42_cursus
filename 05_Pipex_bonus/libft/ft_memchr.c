/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:26:32 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:57:04 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Description: Locates the first occurrence of c in the first n bytes of the */
/* memory area pointed to by s.                                               */
void	*ft_memchr(const void	*s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char )c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
