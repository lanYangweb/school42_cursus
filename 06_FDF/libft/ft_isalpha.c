/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:33:54 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:44:36 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

#include "libft.h"
/* Description: Checks if the given character is an alphabetic letter.        */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	else
		return (0);
}

/* int main(int ac, char **av)
{
	int n1;
	int n2;

	if (ac < 2)
	{
		printf("Put your character.");
		return (0);
	}
	n1 = ft_isalpha(av[1][0]);
	n2 = isalpha(av[1][0]);
	printf("ft_isalpha: %d\n", n1);
	printf("isalpha: %d\n", n2);
	return (0);
} */