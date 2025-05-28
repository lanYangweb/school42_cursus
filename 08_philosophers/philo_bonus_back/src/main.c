/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:31:37 by layang            #+#    #+#             */
/*   Updated: 2025/05/19 16:37:53 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	eat_sleep_think(t_philo	*philo)
{
	sem_wait(philo->tab->sems->sem_forks);
	print_status(FORK_1, philo);
	sem_wait(philo->tab->sems->sem_forks);
	print_status(FORK_1, philo);
	print_status(EATING, philo);
	sem_wait(philo->s_phi);
	philo->last_meal = ft_get_time();
	sem_post(philo->s_phi);
	philo_pass_time(philo->tab->t_eat);
	sem_wait(philo->s_phi);
	philo->nb_eatp += 1;
	if (philo->nb_eatp == philo->tab->nb_eat)
		sem_post(philo->tab->sems->eat_counter);
	sem_post(philo->s_phi);
	print_status(SLEEPING, philo);
	sem_post(philo->tab->sems->sem_forks);
	sem_post(philo->tab->sems->sem_forks);
	philo_pass_time(philo->tab->t_sleep);
	print_status(THINKING, philo);
}

static void	run_child_philo(t_table	*tab, int i)
{
	pthread_t	tid_dead;
	t_philo		*philo;

	philo = tab->philos[i];
	sem_wait(philo->s_phi);
	philo->last_meal = philo->tab->start_time;
	sem_post(philo->s_phi);
	aligned_time(philo->tab->start_time);
	if (pthread_create(&tid_dead, NULL, &monitor_death, tab->philos[i]) != 0)
		failed_thread("create monitor eat thread", 1, tab);
	if (pthread_detach(tid_dead) != 0)
	{
		pthread_join(tid_dead, NULL),
		failed_thread("detach monitor eat thread", 1, tab);
	}
	while (1)
	{
		if (philo->id % 2)
			philo_pass_time(1);
		eat_sleep_think(philo);
	}
}

static int	ft_start_philo(t_table	*tab)
{
	int			i;
	pthread_t	tid_meal;
	pid_t		pid_d;

	tab->start_time = ft_get_time() + tab->nb_phi * 20;
	if (tab->nb_eat > 0)
	{
		if (pthread_create(&tid_meal, NULL, &monitor_eat, tab) != 0)
			return (failed_thread("create monitor eat thread", 0, tab), 1);
		if (pthread_detach(tid_meal) != 0)
			return (pthread_join(tid_meal, NULL),
				failed_thread("detach monitor eat thread", 0, tab), 1);
	}
	i = 0;
	while (i < tab->nb_phi)
	{
		tab->pids[i] = fork();
		if (tab->philos[i] < 0)
			return (wait_some_philos(tab, i, -1), 1);
		if (tab->pids[i] == 0)
			run_child_philo(tab, i);
		i++;
	}
	pid_d = waitpid(-1, NULL, 0);
	return (wait_some_philos(tab, i, pid_d), 1);
}

int	main(int ac, char	**av)
{
	t_table		*tab;
	int			init;

	if (ac != 5 && ac != 6)
		return (printf("nb_phi, t_die, t_eat, t_sleep, nb_eat(option)\n"), 0);
	init = init_table(&tab, av);
	if (init)
		return (ft_free_philo(tab, init), 0);
	if (ft_start_philo(tab))
		return (1);
	return (0);
}
