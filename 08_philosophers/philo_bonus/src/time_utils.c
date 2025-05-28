/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:03:41 by layang            #+#    #+#             */
/*   Updated: 2025/05/22 11:33:07 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

void	aligned_time(time_t	now)
{
	while (ft_get_time() < now)
		continue ;
}

void	philo_pass_time(time_t	delay)
{
	time_t	wait_until;

	wait_until = ft_get_time() + delay;
	while (ft_get_time() < wait_until)
		usleep(100);
}

void	print_status(t_status status, t_philo	*philo)
{
	long	now;

	if (status == DIED)
	{
		sem_wait(philo->tab->sems->s_print);
		now = ft_get_time();
		printf("%ld \e[31m%d died\e[0m\n", now - philo->tab->start_time,
			philo->id + 1);
		return ;
	}
	sem_wait(philo->tab->sems->s_print);
	now = ft_get_time();
	if (status == FORK_1 || status == FORK_2)
		printf("%ld %d has taken a fork\n", now - philo->tab->start_time,
			philo->id + 1);
	else if (status == EATING)
		printf("%ld \e[32m%d is eating\e[0m\n", now - philo->tab->start_time,
			philo->id + 1);
	else if (status == SLEEPING)
		printf("%ld %d is sleeping\n", now - philo->tab->start_time,
			philo->id + 1);
	else
		printf("%ld %d is thinking\n", now - philo->tab->start_time,
			philo->id + 1);
	sem_post(philo->tab->sems->s_print);
}

// move from utils.c
int	ft_atoi(const char	*nptr)
{
	int	sign;
	int	i;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}
