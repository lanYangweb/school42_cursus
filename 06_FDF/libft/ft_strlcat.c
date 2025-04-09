/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:55:02 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:55:05 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */

// use ft_strlen

#include "libft.h"
/* Description: Appends the string src to the end of dest, ensuring null-     */
/* termination.                                                               */
size_t	ft_strlcat(char	*dst, const char	*src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	i = 0;
	while (i < size - len_dst - 1 && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/* int	main()
{
	char	dst1[20] = "Hello, ";
	const char	*src = "World!";
	size_t	size = 15;

	size_t	result_ft = ft_strlcat(dst1, src, size);
	printf("ft_strlcat: Result: %s, Length: %zu\n", dst1, result_ft);
	return 0;
} */