/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:26 by layang            #+#    #+#             */
/*   Updated: 2025/05/21 08:37:46 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	open_sems_inchild(t_philo	*ph)
{
	ph->tab->sems->sem_forks = sem_open("/sem_forks", 0);
	if (ph->tab->sems->sem_forks == SEM_FAILED)
		failed_thread("reopen sem_forks", 1, ph->tab);
	ph->tab->sems->s_print = sem_open("/s_print", 0);
	if (ph->tab->sems->s_print == SEM_FAILED)
		failed_thread("reopen s_print", 1, ph->tab);
	ph->tab->sems->s_dead = sem_open("/s_dead", 0);
	if (ph->tab->sems->s_dead == SEM_FAILED)
		failed_thread("reopen s_dead", 1, ph->tab);
	ph->tab->sems->eat_counter = sem_open("/eat_counter",0);
	if (ph->tab->sems->eat_counter == SEM_FAILED) 
		failed_thread("reopen eat_counter", 1, ph->tab);
	ph->tab->sems->s_stop_flag = sem_open("/sem_stop_flag", 0);
	if (ph->tab->sems->s_stop_flag == SEM_FAILED)
		failed_thread("reopen s_stop_flag", 1, ph->tab);
	ph->s_phi = sem_open(ph->s_name, O_CREAT, 0644, 1);
	if (ph->s_phi == SEM_FAILED)
		failed_thread("reopen s_phi", 1, ph->tab);
	if (sem_unlink(ph->s_name) != 0)
		failed_thread("unlink s_phi", 1, ph->tab);
}

static int	init_philos(t_table	*tab)
{
	int		i;

	tab->philos = malloc(sizeof(t_philo *) * tab->nb_phi);
	if (!tab->philos)
		return (perror("malloc philos"), 6);
	i = 0;
	while (i < tab->nb_phi)
	{
		tab->philos[i] = malloc(sizeof(t_philo) * 1);
		if (!tab->philos[i])
			return (perror("malloc each philo"), free_philos(tab, i), 7);
		tab->philos[i]->id = i;
		tab->philos[i]->nb_eatp = 0;
		tab->philos[i]->s_name = strjoin_free("/sem_phi_", ft_utoa(i));
		if (DEBUG_FORMATTING == 1)
		{
			write(1, "s_name: ", 9);
			write(1, tab->philos[i]->s_name,
				ft_strlen(tab->philos[i]->s_name));
			write(1, "\n", 2);
		}
		tab->philos[i]->tab = tab;
		i++;
	}
	return (0);
}

static int	init_sems(t_table	*tab)
{
	sem_unlink("/sem_forks");
	sem_unlink("/s_print");
	sem_unlink("/s_dead");
	sem_unlink("/eat_counter");
	sem_unlink("/sem_stop_flag");
	tab->sems = (t_sems *)malloc(sizeof(t_sems));
	if (!tab->sems)
		return (perror("malloc tab sems"), 1);
	tab->sems->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, tab->nb_phi);
	if (tab->sems->sem_forks == SEM_FAILED)
		return (perror("sem_open sem_forks"), 1);
	tab->sems->s_print = sem_open("/s_print", O_CREAT, 0644, 1);
	if (tab->sems->s_print == SEM_FAILED)
		return (perror("sem_open s_print"), 2);
	tab->sems->s_dead = sem_open("/s_dead", O_CREAT, 0644, 0);
	if (tab->sems->s_dead == SEM_FAILED)
		return (perror("sem_open s_dead"), 3);
	tab->sems->eat_counter = sem_open("/eat_counter", O_CREAT, 0644, 0);
	if (tab->sems->eat_counter == SEM_FAILED)
		return (perror("sem_open eat_counter"), 4);
	tab->sems->s_stop_flag = sem_open("/sem_stop_flag", O_CREAT, 0644, 1);
	if (tab->sems->s_stop_flag == SEM_FAILED)
		return (perror("sem_open s_stop_flag"), 5);
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
	(*tab)->stop_flag = 0;
	start_philos = init_philos(*tab);
	if (start_philos)
		return (start_philos);
	return (0);
}
