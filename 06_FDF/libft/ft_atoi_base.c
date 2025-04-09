/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:08:32 by layang            #+#    #+#             */
/*   Updated: 2025/03/07 16:39:32 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* int	good_base(char	*base)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (base[len] != '\0')
		len++;
	if (len <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (j < len)
		{
			while (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
} */

int	find_value(char c, char	*base)
{
	int	index;

	if (c >= 'A' && c <= 'F')
		c += 32;
	index = 0;
	while (base[index] != '\0')
	{
		if (c == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (find_value(str[i], base) != -1)
	{
		num = num * ft_strlen(base) + find_value(str[i], base);
		i++;
	}
	return (num * sign);
}
/*
int main (void)
{
	char	str[] = " ---+--+ab567";
	char	base16[] = "0123456789abcdef";
	int	result;

	char	str2[] = " -+-evgggy7";
	char	base8[] = "poneyvif";
	int	result2;

	char	str3[] = " ---+--+1234ab567";
	char	base10[] = "0123456789";
	int	result3;

	char	str4[] = " ---+--+agggg7";
	int	result4;

	result = ft_atoi_base(str, base16);
	result2 = ft_atoi_base(str2, base8);
	result3 = ft_atoi_base(str3, base10);
	result4 = ft_atoi_base(str4, base16);

	printf("From: \"%s\"\n", str);
	printf("To: %d\n", result);
	printf("From: \"%s\"\n", str2);
	printf("To: %d\n", result2);
	printf("From: \"%s\"\n", str3);
	printf("To: %d\n", result3);
	printf("From: \"%s\"\n", str4);
	printf("To: %d\n", result4);
	return (0);
}*/
