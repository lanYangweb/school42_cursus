/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:59:57 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:53:43 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// use ft_strlen

#include "libft.h"
/* Description: Copies up to size - 1 characters from the string src to dest, */
/* null-terminating the result.                                               */
size_t	ft_strlcpy(char	*dst, const	char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
