/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:30:03 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:51:13 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
// size_t = unsigned 8 bytes integer, const: not to modify -> good practice
#include "libft.h"
/* Description: Computes the length of the given string.                      */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/* int main()
{
	char c[100];

	printf("Enter your string: ");
	scanf("%99s", c);
	printf("ft_strlen: %lu\n", ft_strlen(c));
	printf("strlen: %lu\n", strlen(c));
	return (0);
} */