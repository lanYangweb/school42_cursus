/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:50:06 by layang            #+#    #+#             */
/*   Updated: 2025/05/16 12:49:23 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think_routine(t_philo	*philo, int delay)
{
	time_t	think_time;

	pthread_mutex_lock(&philo->philo_lock);
	think_time = (philo->tab->t_die - (ft_get_time()
				- philo->last_meal) - philo->tab->t_eat) / 2;
	pthread_mutex_unlock(&philo->philo_lock);
	if (think_time < 0)
		think_time = 0;
	if (think_time == 0 && delay)
		think_time = 1;
	if (think_time > 600)
		think_time = 200;
	if (!delay)
		print_status(THINKING, philo, stop_arrived(philo->tab) == 0);
	philo_pass_time(philo->tab, think_time);
}

static void	eat_sleep_routine(t_philo	*philo)
{
	pthread_mutex_lock(&philo->tab->forks_locks[philo->fork[0]]);
	print_status(FORK_1, philo, stop_arrived(philo->tab) == 0);
	pthread_mutex_lock(&philo->tab->forks_locks[philo->fork[1]]);
	print_status(FORK_2, philo, stop_arrived(philo->tab) == 0);
	print_status(EATING, philo, stop_arrived(philo->tab) == 0);
	pthread_mutex_lock(&philo->philo_lock);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->philo_lock);
	philo_pass_time(philo->tab, philo->tab->t_eat);
	if (!stop_arrived(philo->tab))
	{
		pthread_mutex_lock(&philo->philo_lock);
		philo->nb_eatp += 1;
		pthread_mutex_unlock(&philo->philo_lock);
	}
	print_status(SLEEPING, philo, stop_arrived(philo->tab) == 0);
	pthread_mutex_unlock(&philo->tab->forks_locks[philo->fork[0]]);
	pthread_mutex_unlock(&philo->tab->forks_locks[philo->fork[1]]);
	philo_pass_time(philo->tab, philo->tab->t_sleep);
}

static void	*only_one_philo(t_philo	*philo)
{
	pthread_mutex_lock(&philo->tab->forks_locks[philo->fork[0]]);
	print_status(FORK_1, philo, 1);
	philo_pass_time(philo->tab, philo->tab->t_die);
	pthread_mutex_unlock(&philo->tab->forks_locks[philo->fork[0]]);
	print_status(DIED, philo, 1);
	return (NULL);
}

void	*philosopher(void	*data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->philo_lock);
	philo->last_meal = philo->tab->start_time;
	pthread_mutex_unlock(&philo->philo_lock);
	aligned_time(philo->tab->start_time);
	if (philo->tab->t_die == 0)
		return (NULL);
	if (philo->tab->nb_phi == 1)
		return (only_one_philo(philo));
	else if (philo->id % 2)
		think_routine(philo, 1);
	while (!stop_arrived(philo->tab))
	{
		eat_sleep_routine(philo);
		think_routine(philo, 0);
	}
	return (NULL);
}
