/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:25 by layang            #+#    #+#             */
/*   Updated: 2025/05/19 20:22:54 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// in parent process
/* void	*monitor_death_main(void	*ptr)
{
	t_table	*tab;

	tab = (t_table	*)ptr;
	sem_wait(tab->sems->s_dead);
	wait_some_philos(tab, tab->nb_phi, -1);
	exit(0);
	//return (NULL);
} */
void	*monitor_death_main(void	*ptr)
{
	t_table	*tab;

	tab = (t_table	*)ptr;
	sem_wait(tab->sems->s_dead);
	sem_wait(tab->sems->s_stop_flag);
	tab->stop_flag = 1;
	sem_post(tab->sems->s_stop_flag);	
	return (NULL);
}

// in each philo process, need exit
void	*monitor_death(void	*ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		sem_wait(philo->s_phi);
		if (ft_get_time() - philo->last_meal >= philo->tab->t_die)
		{
			print_status(DIED, philo);
			sem_post(philo->s_phi);
			//ft_free_philo(philo->tab, 8);
			sem_post(philo->tab->sems->s_dead);
			free(philo->s_name);
			sem_close(philo->s_phi);
			free(philo);
			philo = NULL;
			exit(1);
		}
		sem_post(philo->s_phi);
		usleep(100);
	}
	return (NULL);
}

/* void	*monitor_death(void	*ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		sem_wait(philo->s_phi);
		if (ft_get_time() - philo->last_meal >= philo->tab->t_die)
		{
			print_status(DIED, philo);
			sem_post(philo->s_phi);
			free(philo->s_name);
			if (philo->s_phi != SEM_FAILED)
				sem_close(philo->s_phi);
			free(philo);
			philo = NULL;
			exit(1);
		}
		sem_post(philo->s_phi);
	}
	return (NULL);
} */

// in parent process
/* void	*monitor_eat(void	*ptr)
{
	int		i;
	t_table	*tab;

	tab = (t_table *)ptr;
	i = 0;
	while (1)
	{
		sem_wait(tab->sems->eat_counter);
		i++;
		if (i >= tab->nb_phi)
		{
			wait_some_philos(tab, tab->nb_phi, -1);
			exit(0);
		}
	}
	return (NULL);
} */
void	*monitor_eat(void	*ptr)
{
	int		i;
	t_table	*tab;

	tab = (t_table *)ptr;
	i = 0;
	while (1)
	{
		sem_wait(tab->sems->eat_counter);
		i++;
		if (i >= tab->nb_phi)
		{
			sem_wait(tab->sems->s_stop_flag);
			tab->stop_flag = 1;
			sem_post(tab->sems->s_stop_flag);	
			return (NULL);
		}
	}
	return (NULL);
}
