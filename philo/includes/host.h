/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:06:03 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:12:17 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOST_H
# define HOST_H
# include "philosopher.h"

// Also can be referred as a waiter
typedef struct s_host
{
	t_bool	*stop;
	t_philo	*table;
	int		number_of_philos;
}	t_host;

// Creates host
int	create_host(t_philo *philos, int number_of_philos, \
	t_bool *stop, t_host *host);

#endif
