/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_monitor_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 03:58:47 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:12:17 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*start_eating_monitor(void *arg)
{
	t_sem_context	*sem_context;
	int				i;

	sem_context = (t_sem_context *)arg;
	i = -1;
	sem_wait(sem_context->print_sem);
	while (++i < sem_context->number_of_philos)
	{
		sem_post(sem_context->print_sem);
		sem_wait(sem_context->eat_enough_sem);
		sem_wait(sem_context->print_sem);
	}
	sem_post(sem_context->stop_sem);
	return (NULL);
}
