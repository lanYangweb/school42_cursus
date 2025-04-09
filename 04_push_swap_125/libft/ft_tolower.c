/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:18:15 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:55:29 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

#include "libft.h"
/* Description: Converts an uppercase letter to lowercase.                    */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/* int main()
{
	char c;

	printf("Enter your character: ");
	scanf("%c", &c);
	printf("ft_tolower: %d\n", ft_tolower(c));
	printf("tolower: %d\n", tolower(c));
	return (0);
} */