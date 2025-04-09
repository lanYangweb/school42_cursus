/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:31:53 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:56:18 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */

#include "libft.h"
/* Description: Locates the last occurrence of c in the string s.             */
char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last);
}

/* int	main()
{
	const char *str;
	char c;
	char *result_ft;
	char *result_std;

	str = "Hello, World!";
	c = 'o';
	result_ft = ft_strrchr(str, c);
	result_std = strrchr(str, c);

	if (result_ft)
		printf("ft_strrchr: Found '%c' at position: %ld\n", c, result_ft - str);
	else
		printf("ft_strrchr: '%c' not found\n", c);

	if (result_std)
		printf("strrchr: Found '%c' at position: %ld\n", c, result_std - str);
	else
		printf("strrchr: '%c' not found\n", c);

	return (0);
} */