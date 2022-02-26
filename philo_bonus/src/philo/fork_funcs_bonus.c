/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funcs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:39:18 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:32:37 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fork_funcs_bonus.h"
#include "message_printer_bonus.h"
#include <pthread.h>

void	take_right_fork(t_philo *philo)
{
	sem_wait(philo->s_ctx.forks_sem);
	print_fork_take_message(philo);
}

void	take_left_fork(t_philo *philo)
{
	sem_wait(philo->s_ctx.forks_sem);
	print_fork_take_message(philo);
}
