/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conc_usleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:25:38 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:12:17 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "utils.h"

void	conc_usleep(int64_t ms)
{
	int64_t	time;

	time = gettime_in_ms();
	usleep(ms * 920);
	while (gettime_in_ms() < time + ms)
		usleep(ms * 3);
}
