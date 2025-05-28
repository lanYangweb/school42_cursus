/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:16:13 by layang            #+#    #+#             */
/*   Updated: 2025/05/16 12:50:59 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	found_dead(t_philo	*philo)
{
	time_t	now;

	now = ft_get_time();
	if ((now - philo->last_meal) >= philo->tab->t_die)
	{
		set_stop_flag(philo->tab, true);
		print_status(DIED, philo, 1);
		pthread_mutex_unlock(&philo->philo_lock);
		return (1);
	}
	return (0);
}

static int	end_reached(t_table	*tab)
{
	int	meal_enough;
	int	i;

	meal_enough = 1;
	i = 0;
	while (i < tab->nb_phi)
	{
		pthread_mutex_lock(&tab->philos[i]->philo_lock);
		if (found_dead(tab->philos[i]))
			return (1);
		if (tab->nb_eat != -1 && (tab->philos[i]->nb_eatp < tab->nb_eat))
			meal_enough = 0;
		pthread_mutex_unlock(&tab->philos[i]->philo_lock);
		i++;
	}
	if (tab->nb_eat != -1 && meal_enough == 1)
	{
		set_stop_flag(tab, true);
		return (1);
	}
	return (0);
}

void	*ft_killer(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	set_stop_flag(table, false);
	aligned_time(table->start_time);
	while (!end_reached(table))
		usleep(1000);
	return (NULL);
}
