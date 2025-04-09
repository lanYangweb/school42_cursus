/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:13:29 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 12:10:43 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

#include "libft.h"
/* Description: Checks if the given character is alphanumeric (a letter or a
digit). */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	else
		return (0);
}

/* int	main()
{
	char	c;

	printf("Enter your character: ");
	scanf("%c", &c);
	printf("ft_isalnum: %d\n", ft_isalnum(c));
	printf("isalnum: %d\n", isalnum(c));
	return (0);
} */
