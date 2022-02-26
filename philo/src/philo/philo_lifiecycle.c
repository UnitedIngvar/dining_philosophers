/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifiecycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:22:44 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/30 20:03:32 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "philo.h"
#include "host.h"
#include "message_printer.h"
#include "pthread.h"
#include "timer.h"
#include "includes/fork_funcs.h"
#include "stdio.h"

// Eats and puts the forks back on the table
static void	philo_eat(t_philo *philo)
{
	print_eating_message(philo);
	if (*(philo->stop) == true)
		return ;
	philo->last_meal_time = get_timestamp_in_ms();
	conc_usleep(philo->time_to_eat);
	if (philo->num_of_eats != NOTDEFINED)
		philo->num_of_eats--;
	pthread_mutex_unlock(philo->left_fork->mutex);
	philo->left_fork->turn = left;
	philo->has_left_fork = false;
	pthread_mutex_unlock(philo->right_fork->mutex);
	philo->right_fork->turn = right;
	philo->has_right_fork = false;
}

// Thinks until has both forks
static void	philo_think(t_philo *philo)
{
	t_bool	slept;

	slept = false;
	print_thinking_message(philo);
	while (!philo->has_left_fork || !philo->has_right_fork)
	{
		if (philo->left_fork->turn == right && !philo->has_left_fork)
			take_left_fork(philo);
		if (philo->right_fork->turn == left && !philo->has_right_fork)
			take_right_fork(philo);
		if (!slept && philo->big_num_optim)
		{
			conc_usleep(philo->time_to_eat);
			slept = true;
		}
		if (*(philo->stop) == true)
			return (fold_forks_on_stop(philo));
	}
}

// Sleeps after eating
static void	philo_sleep(t_philo *philo)
{
	print_sleeping_message(philo);
	conc_usleep(philo->time_to_sleep);
}

// Philo lifecycle
void	*start_philo_lifecycle(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	while (*(philo->stop) != true)
	{
		if (philo->left_fork == NULL || philo->right_fork == NULL)
			break ;
		philo_think(philo);
		if (*(philo->stop) == true)
			break ;
		philo_eat(philo);
		if (philo->num_of_eats == 0)
		{
			philo->finished = true;
			break ;
		}
		if (*(philo->stop) == true)
			break ;
		philo_sleep(philo);
		if (*(philo->stop) == true)
			break ;
	}
	return (NULL);
}
