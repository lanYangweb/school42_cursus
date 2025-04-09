/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:12:58 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:53:28 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Description: Moves n bytes from memory area src to memory area dest,       */
/* handling overlapping regions.                                              */
void	*ft_memmove(void	*dst, const void	*src, size_t n)
{
	size_t	i;

	if (dst == src || n == 0)
		return (dst);
	if (dst < src)
	{
		ft_memcpy(dst, src, n);
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		}
	}
	return (dst);
}
