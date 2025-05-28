/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:25 by layang            #+#    #+#             */
/*   Updated: 2025/05/19 17:21:09 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// in each philo process, need exit
void	*monitor_death(void	*ptr)
{
	t_philo	*philo;

	philo = (t_philo	*)ptr;
	while (1)
    {
		sem_wait(philo->s_phi);
		if (ft_get_time() - philo->last_meal >= philo->tab->t_die)
		{
            print_status(DIED, philo);
			sem_post(philo->s_phi);
			ft_free_philo(philo->tab, 8);
			exit(1);
		}
		sem_post(philo->s_phi);	
	}
	return (NULL);
}

// in parent process
void	*monitor_eat(void	*ptr)
{
	int		i;
	t_table	*tab;

	tab = (t_table	*)ptr;
	i = 0;
	while (1)
	{
		sem_wait(tab->sems->eat_counter);
		i++;
		if (i >= tab->nb_phi)
		{
			wait_some_philos(tab, tab->nb_phi, NULL);
			exit(0);
		}
	}
	return (NULL);
}
