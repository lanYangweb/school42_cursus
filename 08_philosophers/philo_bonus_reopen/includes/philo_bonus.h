/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:19:02 by layang            #+#    #+#             */
/*   Updated: 2025/05/21 07:56:36 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <fcntl.h>
# include <signal.h>

# ifndef DEBUG_FORMATTING
#  define DEBUG_FORMATTING 0
# endif

typedef struct s_philo	t_philo;

typedef struct s_sems
{
	sem_t			*sem_forks;
	sem_t			*s_print;
	sem_t			*s_dead;
	sem_t			*eat_counter;
	sem_t			*s_stop_flag;
}	t_sems;

typedef struct s_table
{
	int				nb_phi;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				nb_eat;
	int				stop_flag;
	pthread_t		tid_death;
	pthread_t		tid_meal;	
	pid_t			*pids;
	t_sems			*sems;
	t_philo			**philos;
	long			start_time;
}	t_table;

typedef struct s_philo
{
	unsigned int	id;
	int				nb_eatp;
	time_t			last_meal;
	char			*s_name;
	sem_t			*s_phi;
	t_table			*tab;
}	t_philo;

typedef enum e_status
{
	FORK_1 = 0,
	FORK_2 = 1,
	EATING = 2,
	SLEEPING = 3,
	THINKING = 4,
	DIED = 5,
}	t_status;

/* main.c  4*/
/* init.c  5*/
void	open_sems_inchild(t_philo	*ph);
int		init_table(t_table	**tab, char	**av);
/* monitor.c  3*/
void	*monitor_death_main(void	*ptr);
void	*monitor_eat(void	*ptr);
void	*monitor_death(void	*ptr);
/* free.c  5*/
void	free_philos(t_table	*tab, int size);
void	ft_free_philo(t_table	*tab, int sign);
void	wait_some_philos(t_table *tab, int nb_created, pid_t dead_pid);
void	failed_thread(char	*err, int sign, t_table	*tab);
/* utils.c  5*/
size_t	ft_strlen(const char *s);
int		ft_atoi(const char	*nptr);
char	*ft_utoa(unsigned int n);
char	*strjoin_free(char const *s1, char const *s2);
/* time_utils.c  4*/
long	ft_get_time(void);
void	aligned_time(time_t	now);
void	philo_pass_time(time_t	delay);
void	print_status(t_status status, t_philo	*philo);

#endif