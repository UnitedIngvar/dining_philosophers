/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:21:18 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:21:15 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "host.h"

static int	create_forks(int number_of_philos, t_fork **forks_out)
{
	pthread_mutex_t	*mutexes;
	int				fork_index;
	t_fork			*forks;

	forks = malloc(sizeof(t_fork) * number_of_philos);
	if (forks == NULL)
		return (-1);
	mutexes = malloc(sizeof(pthread_mutex_t) * number_of_philos);
	if (mutexes == NULL)
		return (-1);
	fork_index = 0;
	while (fork_index < number_of_philos)
	{
		pthread_mutex_init(mutexes + fork_index, NULL);
		forks[fork_index].mutex = mutexes + fork_index;
		fork_index++;
	}
	*forks_out = forks;
	return (0);
}

static void	serve_table(t_philo *philos, t_fork *forks, \
	int number_of_philos)
{
	int		seat_index;

	seat_index = 0;
	if (number_of_philos == 1)
	{
		philos[seat_index].left_fork = forks;
		return ;
	}
	philos[seat_index].left_fork = forks;
	philos[seat_index].right_fork = forks + number_of_philos - 1;
	seat_index = 1;
	while (seat_index < number_of_philos)
	{
		philos[seat_index].right_fork = forks + seat_index - 1;
		philos[seat_index].left_fork = forks + seat_index;
		seat_index++;
	}
}

static void	give_order_to_forks(t_fork *forks, int number_of_philos)
{
	int	count;

	if (number_of_philos == 1)
		return ;
	count = 0;
	while (count < number_of_philos)
	{
		if (ft_is_even(count))
			forks[count].turn = right;
		else
			forks[count].turn = left;
		count++;
	}
}

int	create_table(t_philo *philos, int number_of_philos)
{
	t_fork	*forks;

	if (create_forks(number_of_philos, &forks) != 0)
		return (-1);
	if (forks == NULL)
		return (-1);
	give_order_to_forks(forks, number_of_philos);
	serve_table(philos, forks, number_of_philos);
	return (0);
}
