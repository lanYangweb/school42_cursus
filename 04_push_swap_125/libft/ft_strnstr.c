/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:50:44 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:57:41 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */

#include "libft.h"
/* Description: Locates the first occurrence of the substring needle in the   */
/* string haystack, searching up to len characters.                           */
char	*ft_strnstr(const char	*big, const char	*little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if ((i + j) == len)
				return (NULL);
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/* int main() 
{
	const char *str;
	const char *c;
	char *result_ft;
	size_t len;

	str = "aaabcabcd";
	c = "cd";
	len = 8;
	result_ft = ft_strnstr(str, c, len);

	printf("ft_strnstr:  %s\n", result_ft);
	return (0);
} */
