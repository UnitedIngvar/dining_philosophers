/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_funcs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:31:57 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:12:17 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_FUNCS_H
# define FORK_FUNCS_H

# include "philosopher.h"

void	fold_forks_on_stop(t_philo *philo);

void	take_left_fork(t_philo *philo);

void	take_right_fork(t_philo *philo);

#endif
