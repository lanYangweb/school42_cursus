/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:26:37 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:55:16 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

#include "libft.h"
/* Description: Converts a lowercase letter to uppercase.                     */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/* int main()
{
	char c;

	printf("Enter your character: ");
	scanf("%c", &c);
	printf("ft_toupper: %d\n", ft_toupper(c));
	printf("toupper: %d\n", toupper(c));
	return (0);
} */