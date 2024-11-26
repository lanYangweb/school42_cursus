/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:20:07 by layang            #+#    #+#             */
/*   Updated: 2024/11/18 13:36:09 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
functions to convert decimal, unsigned decimal and hexadecimal numbers.
%d or %i, %u, %x and %X
*/
int	ft_put_un(long long nb)
{
	char	c;
	int		n;

	n = 0;
	if (nb > 9)
		n += ft_put_un(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
	return (n + 1);
}

int	ft_put_n(long long nb)
{
	int		n;

	n = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		n++;
	}
	return (n + ft_put_un(nb));
}

int	ft_put_h(unsigned long nb, char *base)
{
	char	c;
	int		n;

	n = 0;
	if (nb > 15)
		n += ft_put_h(nb / 16, base);
	c = base[nb % 16];
	write(1, &c, 1);
	return (n + 1);
}
