/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_printer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:20:37 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:12:17 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_PRINTER_H
# define MESSAGE_PRINTER_H

# include "philosopher.h"

void	print_fork_take_message(t_philo *philo);

void	print_eating_message(t_philo *philo);

void	print_sleeping_message(t_philo *philo);

void	print_thinking_message(t_philo *philo);

void	print_death_message(t_philo *philo, int64_t death_time);

#endif
