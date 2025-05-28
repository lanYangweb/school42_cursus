/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layang <layang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:21:10 by layang            #+#    #+#             */
/*   Updated: 2025/05/13 12:24:23 by layang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* Description: Converts the initial portion of the string pointed to by str  */
/* to int.                                                                    */
int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	i;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(num * sign));
}

void	set_stop_flag(t_table	*tab, bool stat)
{
	pthread_mutex_lock(&tab->stop_lock);
	tab->stop = stat;
	pthread_mutex_unlock(&tab->stop_lock);
}

int	stop_arrived(t_table	*table)
{
	int	stop;

	stop = 0;
	pthread_mutex_lock(&table->stop_lock);
	if (table->stop == true)
		stop = 1;
	pthread_mutex_unlock(&table->stop_lock);
	return (stop);
}

//print: stop_arrived(philo->tab) == 0 or stop_arrived(tab) == 0
void	print_status(t_status status, t_philo	*philo, int print)
{
	long	now;

	if (!print)
		return ;
	pthread_mutex_lock(&philo->tab->log_lock);
	now = ft_get_time();
	if (status == FORK_1 || status == FORK_2)
		printf("%ld %d has taken a fork\n", now - philo->tab->start_time,
			philo->id + 1);
	else if (status == DIED)
		printf("%ld \e[31m%d died\e[0m\n", now - philo->tab->start_time,
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
	pthread_mutex_unlock(&philo->tab->log_lock);
}

void	failed_thread(char	*err, int sign, t_table	*tab)
{
	set_stop_flag(tab, true);
	perror(err);
	if (sign == -1)
		wait_and_free(tab, 8);
	else
		wait_and_free(tab, 9 + sign);
}
