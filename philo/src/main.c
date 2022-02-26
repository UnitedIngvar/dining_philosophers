/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:12:59 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:23:24 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "philosopher.h"
#include "philo.h"
#include "host.h"
#include "timer.h"

static int	create_threads(int64_t number_of_philos, t_philo *philos, \
	t_host host)
{
	int64_t			count;
	pthread_t		*philo_threads;
	pthread_t		death_host_thread;

	philo_threads = malloc(sizeof(pthread_t) * number_of_philos);
	count = -1;
	if (pthread_create(&death_host_thread, NULL, start_death_host, &host) != 0)
		return (-1);
	while (++count < number_of_philos)
		if (pthread_create(&philo_threads[count], NULL, start_philo_lifecycle, \
			&philos[count]) != 0)
			return (-1);
	count = -1;
	if (pthread_join(death_host_thread, NULL) != 0)
		return (-1);
	while (++count < number_of_philos)
		if (pthread_join(philo_threads[count], NULL) != 0)
			return (-1);
	free(philo_threads);
	return (0);
}

static void	destroy_all(t_philo *philos, int num_of_philos)
{
	int	i;

	pthread_mutex_destroy(philos[0].print_mutex);
	i = -1;
	while (++i < num_of_philos)
		pthread_mutex_destroy(philos[i].left_fork->mutex);
	free(philos[0].print_mutex);
	free(philos->left_fork->mutex);
	free(philos->left_fork);
	free(philos);
}

int	main(int argc, char *argv[])
{
	t_philo			*philos;
	t_params		params;
	t_host			host;
	t_bool			stop_sig;

	start_program_timer();
	if (validate_and_parse_input(argc, argv, &params) != 0)
		return (-1);
	stop_sig = false;
	if (create_philos(params, &stop_sig, &philos) != 0)
		return (-1);
	if (philos == NULL)
		return (-1);
	if (create_table(philos, params.number_of_philos) != 0)
		return (-1);
	if (create_host(philos, params.number_of_philos, &stop_sig, &host) != 0)
		return (-1);
	if (create_threads(params.number_of_philos, philos, host) != 0)
		return (-1);
	destroy_all(philos, params.number_of_philos);
	return (0);
}
