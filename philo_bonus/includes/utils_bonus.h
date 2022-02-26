/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:17:42 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:30:09 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

t_bool	ft_isdigit(int c);
t_bool	ft_isspace(char c);
int64_t	gettime_in_ms(void);
void	conc_usleep(int64_t ms);
int64_t	ft_atol(const char *str);
t_bool	ft_is_number(char *str);

#endif
