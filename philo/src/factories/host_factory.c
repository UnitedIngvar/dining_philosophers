/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host_factory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:07:30 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:12:17 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "host.h"
#include "utils.h"

int	create_host(t_philo *philos, int number_of_philos, \
	t_bool *stop, t_host *host)
{
	host->table = philos;
	host->number_of_philos = number_of_philos;
	host->stop = stop;
	return (0);
}
