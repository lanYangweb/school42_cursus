/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:24:14 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 12:05:55 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Allocates and returns a string representing the integer received as an argument.
*/
static int	len(long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*c;
	long	nb;
	int		l;

	nb = (long)n;
	l = len(nb);
	c = (char *)malloc(l + 1);
	if (!c)
		return (NULL);
	c[l--] = '\0';
	if (nb < 0)
	{
		c[0] = '-';
		nb = -nb;
	}
	while (nb > 9)
	{
		c[l] = (nb % 10) + '0';
		nb /= 10;
		l--;
	}
	c [l] = (nb % 10) + '0';
	return (c);
}
