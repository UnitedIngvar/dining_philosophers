/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_stuff_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 04:30:20 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:33:54 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "philosopher_bonus.h"
#include "philo_bonus.h"
#include "pthread.h"

static void	create_death_host(t_philo *philo)
{
	pthread_t	tid;

	if (pthread_create(&tid, NULL, start_death_monitor, philo))
		exit(0);
	pthread_detach(tid);
}

void	kill_processes(t_philo *philos, int number_of_philos)
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		kill(philos[i].pid, SIGKILL);
		i++;
	}
}

int	create_processes(int64_t number_of_philos, t_philo *philos)
{
	int		i;

	i = 0;
	create_eating_monitor(philos);
	while (i < number_of_philos)
	{
		philos[i].pid = fork();
		if (philos[i].pid == -1)
		{
			while (--i >= 0)
				kill(philos[i].pid, SIGKILL);
			return (-1);
		}
		else if (philos[i].pid == 0)
		{
			create_death_host(philos + i);
			start_philo_lifecycle(philos + i);
			exit(0);
		}
		i++;
	}
	sem_wait(philos->s_ctx.stop_sem);
	return (0);
}

void	create_eating_monitor(t_philo *philo)
{
	pthread_t	tid;

	if (philo->num_of_eats != NOTDEFINED)
	{
		if (pthread_create(&tid, NULL, start_eating_monitor, &(philo->s_ctx)))
			exit(-1);
		pthread_detach(tid);
	}
}
