/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:41:25 by layang            #+#    #+#             */
/*   Updated: 2025/01/23 13:57:53 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi_ctl(const char	*str)
{
	int		sign;
	long	num;
	int		i;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > (2147483647 - (str[i] - '0')) / 10)
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

static int	check_repeat(char	**av, int nb, int ac)
{
	int	i;
	int	j;

	i = 0;
	if (nb == 1)
	{
		free_array(av, nb);
		return (1);
	}
	while (i < nb)
	{
		j = i + 1;
		while (j < nb)
		{
			if (ft_atoi_ctl(av[i]) == ft_atoi_ctl(av[j]))
			{
				if (ac == 2)
					free_array(av, nb);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static t_stack	*initialize_tab(char	**av, int nb, int ac)
{
	t_stack	*tab;

	tab = malloc(sizeof(t_stack));
	if (!tab)
	{
		if (ac == 2)
			free_array(av, nb);
		return (NULL);
	}
	tab->a = put_a(av);
	if (!tab->a)
	{
		free(tab);
		if (ac == 2)
			free_array(av, nb);
		return (NULL);
	}
	tab->b = NULL;
	return (tab);
}

void	checker(t_stack	**tab, char	**av, int nb, int ac)
{
	char	*input;

	*tab = initialize_tab(av, nb, ac);
	if (!tab)
		return ;
	input = get_next_line(0);
	while (input)
	{
		if (!instruct(input, *tab))
		{
			ft_putstr_fd("Error\n", 1);
			exit(-1);
		}
		input = get_next_line(0);
	}
	if (is_sorted_a((*tab)->a) && !(*tab)->b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char	**av)
{
	int		nb;
	t_stack	*tab;

	nb = 0;
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		while (av[nb])
		{
			if (ft_atoi_ctl(av[nb]) == 0 && av[nb][0] != '0')
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			nb++;
		}
	}
	if (check_repeat(av, nb, ac))
		ft_putstr_fd("Error\n", 2);
	else
		checker(&tab, av, nb, ac);
	return (0);
}
