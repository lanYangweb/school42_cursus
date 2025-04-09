/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:21:10 by layang            #+#    #+#             */
/*   Updated: 2024/11/12 12:11:29 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdlib.h>
#include <stdio.h> */
#include "libft.h"
/* Description: Converts the initial portion of the string pointed to by str  */
/* to int.                                                                    */
int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	i;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

/* int	main(int ac, char	**av)
{
	int	n1;
	int	n2;

	if (ac < 2)
	{
		printf("Put your number.");
		return (0);
	}	
	n1 = ft_atoi(av[1]);
	n2 = atoi(av[1]);
	printf("ft_atoi: %d\n", n1);
	printf("atoi: %d\n", n2);
	return (0);
} */
