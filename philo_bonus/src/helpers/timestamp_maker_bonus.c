/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp_maker_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:24:15 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:12:17 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static int64_t	*get_start_time(void)
{
	static int64_t	start_time;

	return (&start_time);
}

void	start_program_timer(void)
{
	int64_t	*start_time;

	start_time = get_start_time();
	*start_time = gettime_in_ms();
}

int64_t	get_timestamp_in_ms(void)
{
	int64_t	*start_time;

	start_time = get_start_time();
	return (gettime_in_ms() - *start_time);
}
