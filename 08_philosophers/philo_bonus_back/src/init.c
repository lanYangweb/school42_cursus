/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:26 by layang            #+#    #+#             */
/*   Updated: 2025/05/19 14:37:12 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_philos(t_table	*tab)
{
	int		i;
	t_philo	*phi;

	tab->philos = malloc(sizeof(t_philo *) * tab->nb_phi);
	if (!tab->philos)
		return (perror("malloc philos"), 6);
	i = 0;
	while (i < tab->nb_phi)
	{
		tab->philos[i] = malloc(sizeof(t_philo) * 1);
		if (!tab->philos[i])
			return (perror("malloc each philo"), free_philos(tab, i), 7);
		phi = tab->philos[i];
		phi->id = i;
		phi->nb_eatp = 0;
		phi->s_name = strjoin_free("/sem_phi_", ft_utoa(i));
		phi->s_phi = sem_open(phi->s_name, O_CREAT, 0644, 1);
		if (phi->s_phi == SEM_FAILED)
			return (perror("sem phi"), free_philos(tab, i), 7);
		if (sem_unlink(phi->s_name) != 0)
			return (perror("unlink sem phi"), free_philos(tab, i), 7);
		phi->tab = tab;
		i++;
	}
	return (0);
}

/* 	sem_unlink("/sem_forks");
	sem_unlink("/s_print");
	sem_unlink("/eat_counter"); */
static int	init_sems(t_table	*tab)
{
	tab->sems = (t_sems *)malloc(sizeof(t_sems));
	if (!tab->sems)
		return (perror("malloc tab sems"), 1);
	tab->sems->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, tab->nb_phi);
	if (tab->sems->sem_forks == SEM_FAILED)
		return (perror("sem_open sem_forks"), 1);
	tab->sems->s_print = sem_open("/s_print", O_CREAT, 0644, 1);
	if (tab->sems->s_print == SEM_FAILED)
		return (perror("sem_open s_print"), 2);
	tab->sems->s_dead = sem_open("/s_dead", O_CREAT, 0644, 1);
	if (tab->sems->s_dead == SEM_FAILED)
		return (perror("sem_open s_dead"), 3);
	tab->sems->eat_counter = sem_open("/eat_counter", O_CREAT, 0644, 0);
	if (tab->sems->eat_counter == SEM_FAILED)
		return (perror("sem_open eat_counter"), 4);
	if (sem_unlink("/sem_forks") || sem_unlink("/s_print")
		|| sem_unlink("/s_dead") || sem_unlink("/eat_counter"))
		return (perror("unlink in free"), 5);
	return (0);
}

static int	wrong_input_check(t_table	*tab, char	*av5)
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

int	init_table(t_table	**tab, char	**av)
{
	int	start_sems;
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
	(*tab)->pids = (pid_t *)malloc(sizeof(pid_t) * (*tab)->nb_phi);
	if (!(*tab)->pids)
		return (-1);
	start_sems = init_sems(*tab);
	if (start_sems)
		return (start_sems);
	start_philos = init_philos(*tab);
	if (start_philos)
		return (start_philos);
	return (0);
}
