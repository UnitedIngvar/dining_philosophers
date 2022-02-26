/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:32:24 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/29 21:12:30 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include <utils.h>

# define NOTDEFINED -1					// Represents undefined value.

// Enum that helps understand which philo's turn it is to take fork
typedef enum e_turn
{
	right = 1,
	left = 2
}			t_e_turn;

// Fork implemented as a mutex with
// a little more control over the order
// of philosophers taking the fork.
typedef struct s_fork
{
	pthread_mutex_t	*mutex;
	t_e_turn		turn;
}				t_fork;

// Philosopher
typedef struct s_philo
{
	int				id;
	t_bool			*stop;
	int64_t			time_to_die;
	int64_t			time_to_eat;
	int64_t			time_to_sleep;
	int64_t			sleep_time_left;
	int64_t			last_meal_time;
	int64_t			num_of_eats;
	pthread_mutex_t	*print_mutex;
	t_fork			*right_fork;
	t_bool			has_right_fork;
	t_fork			*left_fork;
	t_bool			has_left_fork;
	t_bool			finished;
	t_bool			big_num_optim;
}				t_philo;

#endif
