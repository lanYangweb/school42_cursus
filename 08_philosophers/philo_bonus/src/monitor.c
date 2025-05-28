/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:25 by layang            #+#    #+#             */
/*   Updated: 2025/05/20 20:54:29 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	sem_post_once(t_table	*tab)
{
	static int	flag = 0;

	sem_wait(tab->sems->s_stop_flag);
	if (!flag)
	{
		if (DEBUG_FORMATTING == 1)
			write(1, "==> setting stop_flag and posting stop sem\n", 44);
		tab->stop_flag = 1;
		sem_post(tab->sems->s_stop_flag);
		sem_post(tab->sems->s_stop_flag);
		flag = 1;
	}
	else
		sem_post(tab->sems->s_stop_flag);
}

void	*monitor_death_main(void	*ptr)
{
	t_table	*tab;
	int		i;

	tab = (t_table *)ptr;
	sem_wait(tab->sems->s_dead);
	sem_post_once(tab);
	i = 0;
	while (i < tab->nb_phi)
	{
		sem_post(tab->sems->eat_counter);
		i++;
	}
	return (NULL);
}

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
			if (DEBUG_FORMATTING == 1)
				write(1, "=> have eaten enough times / =>has death\n", 46);
			sem_post_once(tab);
			sem_post(tab->sems->s_dead);
			return (NULL);
		}
	}
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
