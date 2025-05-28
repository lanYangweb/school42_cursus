/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:16:08 by layang            #+#    #+#             */
/*   Updated: 2025/05/16 12:48:46 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo	*philo, int nb)
{
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % nb;
		philo->fork[1] = philo->id;
	}
	else
	{
		philo->fork[0] = philo->id;
		philo->fork[1] = (philo->id + 1) % nb;
	}
}

static int	init_philos(t_table	*tab)
{
	int	i;

	tab->philos = malloc(sizeof(t_philo *) * tab->nb_phi);
	if (!tab->philos)
		return (perror("malloc philos"), 3);
	i = 0;
	while (i < tab->nb_phi)
	{
		tab->philos[i] = malloc(sizeof(t_philo) * 1);
		if (!tab->philos[i])
			return (perror("malloc each philo"),
				destory_mutex_inphilos(tab->philos, i), 4);
		if (pthread_mutex_init(&tab->philos[i]->philo_lock, 0) != 0)
			return (perror("pthread mutex philo lock "), free(tab->philos[i]),
				destory_mutex_inphilos(tab->philos, i), 4);
		tab->philos[i]->id = i;
		tab->philos[i]->nb_eatp = 0;
		assign_forks(tab->philos[i], tab->nb_phi);
		tab->philos[i]->tab = tab;
		i++;
	}
	return (0);
}

static int	init_forks(t_table	*tab)
{
	int	i;

	tab->forks_locks = malloc(sizeof(pthread_mutex_t) * tab->nb_phi);
	if (!tab->forks_locks)
		return (perror("malloc forks locks"), 1);
	i = 0;
	while (i < tab->nb_phi)
	{
		if (pthread_mutex_init(&tab->forks_locks[i], NULL) != 0)
		{
			perror("pthread mutex fork locks");
			destory_mutex(tab->forks_locks, i);
			return (2);
		}
		i++;
	}
	return (0);
}

int	init_table(t_table	**tab, char	**av)
{
	int	start_forks;
	int	start_philos;

	*tab = malloc(sizeof(t_table));
	if (!*tab)
		return (perror("malloc table"), -1);
	(*tab)->nb_phi = ft_atoi(av[1]);
	(*tab)->t_die = ft_atoi(av[2]);
	(*tab)->t_eat = ft_atoi(av[3]);
	(*tab)->t_sleep = ft_atoi(av[4]);
	if (wrong_input_check(*tab, av[5]))
		return (-1);
	start_forks = init_forks(*tab);
	if (start_forks)
		return (start_forks);
	start_philos = init_philos(*tab);
	if (start_philos)
		return (start_philos);
	if (pthread_mutex_init(&(*tab)->log_lock, NULL) != 0)
		return (perror("pthread mutex log lock"), 5);
	(*tab)->stop = false;
	if (pthread_mutex_init(&(*tab)->stop_lock, NULL) != 0)
		return (perror("pthread mutex stop lock"), 6);
	return (0);
}
