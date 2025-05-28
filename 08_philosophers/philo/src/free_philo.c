/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:17:10 by layang            #+#    #+#             */
/*   Updated: 2025/05/16 17:24:07 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wrong_input_check(t_table	*tab, char	*av5)
{
	if (av5)
	{
		if (ft_atoi(av5) < 0)
			return (printf("nb of times must eat should be positive.\n"), -1);
		else
			tab->nb_eat = ft_atoi(av5);
	}
	else
		tab->nb_eat = -1;
	if (tab->nb_eat == 0)
		return (printf("number of times must eat is 0.\n"), -1);
	if (tab->nb_phi <= 0)
		return (printf("number of philo must be 1-250.\n"), -1);
	if (tab->t_die < 0 || tab->t_eat < 0 || tab->t_sleep < 0)
		return (printf("time must be positive.\n"), -1);
	return (0);
}

void	destory_mutex_inphilos(t_philo	**philos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&philos[i]->philo_lock);
		free(philos[i]);
		philos[i] = NULL;
		i++;
	}
}

void	destory_mutex(pthread_mutex_t	*mutxs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&mutxs[i]);
		i++;
	}
}

void	ft_free_philo(t_table	*tab, int sign)
{
	if (sign > 6 && tab->nb_phi > 1)
		pthread_mutex_destroy(&tab->stop_lock);
	if (sign > 5)
		pthread_mutex_destroy(&tab->log_lock);
	if (sign > 4 && tab->philos)
	{
		destory_mutex_inphilos(tab->philos, tab->nb_phi);
		free(tab->philos);
		tab->philos = NULL;
	}
	if (sign > 2 && tab->forks_locks)
	{
		destory_mutex(tab->forks_locks, tab->nb_phi);
		free(tab->forks_locks);
		tab->forks_locks = NULL;
	}
	free(tab);
}

void	wait_and_free(t_table	*tab, int sign)
{
	int	i;
	int	real_nb;

	i = 0;
	if (sign >= 9)
		real_nb = sign - 9;
	else
		real_nb = tab->nb_phi;
	while (i < real_nb)
	{
		pthread_join(tab->philos[i]->thread, NULL);
		i++;
	}
	if (tab->nb_phi > 1 && sign < 8)
		pthread_join(tab->end_thread, NULL);
	ft_free_philo(tab, sign);
}
