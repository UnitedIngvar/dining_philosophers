/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:32:24 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:33:24 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H
# include <semaphore.h>
# include <unistd.h>
# include "utils_bonus.h"

# define FORKS_SEM "p_forks"
# define PRINT_SEM "p_print"
# define STOP_SEM "p_stop"
# define NOTDEFINED -1
# define EAT_ENOUGH_SEM "p_enough"

// Sem context. Shared accross all processes.
typedef struct s_sem_context
{
	int				number_of_philos;
	sem_t			*stop_sem;
	sem_t			*eat_enough_sem;
	sem_t			*print_sem;
	sem_t			*forks_sem;
}	t_sem_context;

// Philosopher's struct
typedef struct s_philo
{
	int				id;
	pid_t			pid;
	int64_t			num_of_eats;
	t_sem_context	s_ctx;
	int64_t			last_meal_time;
	int64_t			time_to_sleep;
	int64_t			time_to_die;
	int64_t			time_to_eat;
}				t_philo;

#endif
