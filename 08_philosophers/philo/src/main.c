/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:54:32 by layang            #+#    #+#             */
/*   Updated: 2025/05/22 11:09:19 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_numeric(const char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	while (*str == ' ')
		str++;
	if (*str == '\0' && i > 0)
		return (1);
	return (0);
}

static int	ft_start_philo(t_table	*tab)
{
	int	i;

	tab->start_time = ft_get_time() + tab->nb_phi * 20;
	i = 0;
	while (i < tab->nb_phi)
	{
		if (pthread_create(&tab->philos[i]->thread, NULL,
				&philosopher, tab->philos[i]) != 0)
			return (failed_thread("create philo thread, stopped", i, tab), 1);
		i++;
	}
	if (tab->nb_phi > 1)
	{
		if (pthread_create(&tab->end_thread, NULL, &ft_killer, tab) != 0)
			return (failed_thread("create end thread, stopped", -1, tab), 1);
	}
	return (0);
}

// ctr on not more than 200 philos and not less than 60ms.
int	main(int ac, char	**av)
{
	t_table		*tab;
	int			init;

	if (ac != 5 && ac != 6)
		return (printf("nb_phi, t_die, t_eat, t_sleep, nb_eat(option)\n"), 0);
	init = init_table(&tab, av);
	if (init < 0)
		return (0);
	if (init)
		return (ft_free_philo(tab, init), 0);
	if (ft_start_philo(tab))
		return (1);
	wait_and_free(tab, 7);
	return (0);
}
