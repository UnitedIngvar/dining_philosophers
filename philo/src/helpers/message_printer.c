/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:04:12 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/30 00:05:22 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "timer.h"
#include "stdio.h"

void	print_fork_take_message(t_philo *philo)
{
	int64_t	timestamp;

	pthread_mutex_lock(philo->print_mutex);
	if (*(philo->stop) == true)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	timestamp = get_timestamp_in_ms();
	printf("%lld %i has taken a fork\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_eating_message(t_philo *philo)
{
	int64_t	timestamp;

	pthread_mutex_lock(philo->print_mutex);
	if (*(philo->stop) == true)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	timestamp = get_timestamp_in_ms();
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_thinking_message(t_philo *philo)
{
	int64_t	timestamp;

	pthread_mutex_lock(philo->print_mutex);
	if (*(philo->stop) == true)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	timestamp = get_timestamp_in_ms();
	printf("%lld %i is thinking\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_death_message(t_philo *philo, int64_t death_time)
{
	printf("%lld %i died\n", death_time, philo->id);
}

void	print_sleeping_message(t_philo *philo)
{
	int64_t	timestamp;

	pthread_mutex_lock(philo->print_mutex);
	if (*(philo->stop) == true)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	timestamp = get_timestamp_in_ms();
	printf("%lld %i is sleeping\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}
