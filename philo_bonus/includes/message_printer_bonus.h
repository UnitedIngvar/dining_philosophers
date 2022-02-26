/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_printer_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:20:37 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/29 22:04:51 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_PRINTER_BONUS_H
# define MESSAGE_PRINTER_BONUS_H

# include "philosopher_bonus.h"

void	print_thinking_message(t_philo *philo);

void	print_fork_take_message(t_philo *philo);

void	print_death_message(t_philo *philo, int64_t death_time);

void	print_sleeping_message(t_philo *philo);

void	print_eating_message(t_philo *philo);

#endif
