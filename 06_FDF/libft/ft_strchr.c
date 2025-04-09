/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:43 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:55:53 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */

#include "libft.h"
/* Description: Locates the first occurrence of c in the string s.            */
char	*ft_strchr(const char	*s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/* int	main()
{
	const char *str;
	char c;
	char *result_ft;
	char *result_std;

	str = "Hello, World!";
	c = '\0';
	result_ft = ft_strchr(str, c);
	result_std = strchr(str, c);

	if (result_ft)
		printf("ft_strchr: Found '%c' at position: %ld\n", c, result_ft - str);
	else
		printf("ft_strchr: '%c' not found\n", c);

	if (result_std)
		printf("strchr: Found '%c' at position: %ld\n", c, result_std - str);
	else
		printf("strchr: '%c' not found\n", c);

	return (0);
} */