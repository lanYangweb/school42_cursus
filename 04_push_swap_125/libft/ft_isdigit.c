/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:23:25 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 11:44:57 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

#include "libft.h"
/* Description: Checks if the given character is a digit (0-9).               */
int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (2048);
	else
		return (0);
}
/* int main()
{
	char c;
	
	printf("Enter your character: ");
	scanf("%c", &c);
	printf("ft_isdigit: %d\n", ft_isdigit(c));
	printf("isdigit: %d\n", isdigit(c));
	return (0);
} */