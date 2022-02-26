/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_factory_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:16:11 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:29:00 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include "philo_bonus.h"

static t_sem_context	create_sem_context(int number_of_philos)
{
	t_sem_context	t_sem_context;

	sem_unlink(PRINT_SEM);
	sem_unlink(FORKS_SEM);
	sem_unlink(EAT_ENOUGH_SEM);
	sem_unlink(STOP_SEM);
	t_sem_context.print_sem = sem_open(PRINT_SEM, O_CREAT | O_EXCL, S_IRWXU, 1);
	t_sem_context.forks_sem = sem_open(FORKS_SEM, O_CREAT | O_EXCL, S_IRWXU, \
		number_of_philos);
	t_sem_context.eat_enough_sem = sem_open(EAT_ENOUGH_SEM, O_CREAT | O_EXCL, \
		S_IRWXU, 0);
	t_sem_context.stop_sem = sem_open(STOP_SEM, O_CREAT | O_EXCL, S_IRWXU, 0);
	t_sem_context.number_of_philos = number_of_philos;
	return (t_sem_context);
}

static t_philo	create_philo(t_params params, int64_t philo_id, \
	t_sem_context sem_context)
{
	t_philo			philo;

	philo.time_to_sleep = params.time_to_sleep;
	philo.num_of_eats = params.num_of_eats;
	philo.last_meal_time = 0;
	philo.id = philo_id;
	philo.s_ctx = sem_context;
	philo.time_to_die = params.time_to_die;
	philo.pid = 0;
	philo.time_to_eat = params.time_to_eat;
	return (philo);
}

int	create_philos(t_params params, t_philo **philos_out)
{
	int64_t			count;
	t_philo			*philos;
	t_sem_context	sem_context;

	philos = malloc(sizeof(t_philo) * params.number_of_philos);
	if (philos == NULL)
		return (-1);
	count = -1;
	sem_context = create_sem_context(params.number_of_philos);
	while (++count < params.number_of_philos)
		philos[count] = create_philo(params, count + 1, sem_context);
	*philos_out = philos;
	return (0);
}
