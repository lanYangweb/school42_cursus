/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:59:56 by layang            #+#    #+#             */
/*   Updated: 2025/05/22 11:11:51 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <string.h> 

# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				nb_phi;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				nb_eat;
	pthread_mutex_t	*forks_locks;
	pthread_mutex_t	log_lock;
	t_philo			**philos;
	bool			stop;
	pthread_mutex_t	stop_lock;
	pthread_t		end_thread;
	long			start_time;
}	t_table;

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	unsigned int	fork[2];
	pthread_mutex_t	philo_lock;
	int				nb_eatp;
	time_t			last_meal;
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

/* mian.c  4 */
int		ft_is_numeric(const char	*str);
/* utils.c  5 */
int		ft_atoi(const char *str);
void	set_stop_flag(t_table	*tab, bool stat);
int		stop_arrived(t_table	*table);
void	print_status(t_status status, t_philo	*philo, int print);
void	failed_thread(char	*err, int sign, t_table	*tab);

/* time_utils.c  3 */
long	ft_get_time(void);
void	aligned_time(time_t	now);
void	philo_pass_time(t_table	*tab, time_t	delay);

/* init.c  4 */
int		init_table(t_table	**tab, char	**av);

/* free_philo.c  5 */
int		wrong_input_check(t_table	*tab, char	*av5);
void	destory_mutex_inphilos(t_philo	**philos, int size);
void	destory_mutex(pthread_mutex_t	*mutxs, int size);
void	ft_free_philo(t_table	*tab, int sign);
void	wait_and_free(t_table	*tab, int sign);

/* start_philo.c  4 */
void	*philosopher(void	*data);

/* end_check.c   3*/
void	*ft_killer(void *data);

#endif
