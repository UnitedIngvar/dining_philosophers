/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_host.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:51:05 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/30 17:19:08 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_printer.h"
#include "host.h"
#include "timer.h"

static void	*stop_execution(t_host host, t_philo dead_philo, \
	int64_t death_time)
{
	pthread_mutex_lock(dead_philo.print_mutex);
	print_death_message(&dead_philo, death_time);
	*(host.stop) = true;
	pthread_mutex_unlock(dead_philo.print_mutex);
	return (NULL);
}

void	*start_death_host(void *host_arg)
{
	int		count;
	int		finised_count;
	int64_t	cur_time;
	t_host	*host;
	t_philo	philo;

	host = (t_host *)host_arg;
	while (true)
	{
		count = 0;
		finised_count = 0;
		cur_time = get_timestamp_in_ms();
		while (count < host->number_of_philos)
		{
			philo = host->table[count];
			if (philo.finished == true)
				finised_count++;
			else if (philo.last_meal_time + philo.time_to_die < cur_time)
				return (stop_execution(*host, philo, cur_time));
			count++;
		}
		if (finised_count >= host->number_of_philos)
			return (NULL);
		usleep(1000);
	}
}
