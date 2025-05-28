/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:12:14 by layang            #+#    #+#             */
/*   Updated: 2025/05/19 17:18:43 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_philos(t_table	*tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab->philos[i])
		{
			free(tab->philos[i]->s_name);
			if (tab->philos[i]->s_phi != SEM_FAILED)
				sem_close(tab->philos[i]->s_phi);
			free(tab->philos[i]);
			tab->philos[i] = NULL;
		}
		i++;
	}
}

static void	close_sem_table(t_table	*tab)
{
	if (tab->sems->sem_forks != SEM_FAILED)
		sem_close(tab->sems->sem_forks);
	if (tab->sems->s_print != SEM_FAILED)
		sem_close(tab->sems->s_print);
	if (tab->sems->s_dead != SEM_FAILED)
		sem_close(tab->sems->s_dead);
	if (tab->sems->eat_counter != SEM_FAILED)
		sem_close(tab->sems->eat_counter);
	if (tab->sems)
		free(tab->sems);
	tab->sems = NULL;
}

void	ft_free_philo(t_table	*tab, int sign)
{
	if (sign > 7 && tab->philos)
		free_philos(tab, tab->nb_phi);
	if (sign > 6 && tab->philos)
	{
		free(tab->philos);
		tab->philos = NULL;
	}
	if (sign >= 1)
	{
		close_sem_table(tab);
		if (tab->pids)
		{
			free(tab->pids);
			tab->pids = NULL;
		}
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	wait_some_philos(t_table *tab, int nb_created, pid_t dead_pid)
{
	int	j;

	j = 0;
	while (j < nb_created)
	{
		if (dead_pid <= 0 || tab->pids[j] != dead_pid)
			waitpid(tab->pids[j], NULL, 0);
		j++;
	}
	ft_free_philo(tab, 8);
}

void	failed_thread(char	*err, int sign, t_table	*tab)
{
	perror(err);
	if (sign == 0)
		ft_free_philo(tab, 8);
	if (sign == 1)
	{
		ft_free_philo(tab, 8);
		exit(1);
	}
}
