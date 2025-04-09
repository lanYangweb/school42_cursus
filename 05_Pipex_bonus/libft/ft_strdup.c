/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:45:28 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:59:01 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
//use ft_strlen and ft_memcpy

#include "libft.h"
/* Description: Allocates sufficient memory for a copy of the string s1,      */
/* does the copy, and returns a pointer to it.                                */
char	*ft_strdup(const char	*src)
{
	int		len;
	int		i;
	char	*in;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	in = (char *)malloc(sizeof(char) * (len + 1));
	if (in == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		in[i] = src[i];
		i++;
	}
	in[len] = '\0';
	return (in);
}

/* int	main()
{
	const char *str;

	str = "Hello, World!";
	printf("ft_strdup: %s \n", ft_strdup(str));
	printf("strdup: %s \n", strdup(str));
	return (0);
} */
