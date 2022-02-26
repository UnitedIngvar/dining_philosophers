/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lifiecycle_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:22:44 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:32:37 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "utils_bonus.h"
#include "philo_bonus.h"
#include "message_printer_bonus.h"
#include "timer_bonus.h"
#include "includes/fork_funcs_bonus.h"

// Sleeps after eating
static void	philo_sleep(t_philo *philo)
{
	print_sleeping_message(philo);
	conc_usleep(philo->time_to_sleep);
}

// Eats and puts the forks back on the table
static void	philo_eat(t_philo *philo)
{
	print_eating_message(philo);
	philo->last_meal_time = get_timestamp_in_ms();
	conc_usleep(philo->time_to_eat);
	if (philo->num_of_eats != NOTDEFINED)
		philo->num_of_eats--;
	sem_post(philo->s_ctx.forks_sem);
	sem_post(philo->s_ctx.forks_sem);
}

// Thinks until has both forks
static void	philo_think(t_philo *philo)
{
	print_thinking_message(philo);
	take_left_fork(philo);
	take_right_fork(philo);
}

// Philo lifecycle
void	*start_philo_lifecycle(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	while (true)
	{
		philo_think(philo);
		philo_eat(philo);
		if (philo->num_of_eats == 0)
		{
			sem_post(philo->s_ctx.eat_enough_sem);
			return (NULL);
		}
		philo_sleep(philo);
	}
	return (NULL);
}
