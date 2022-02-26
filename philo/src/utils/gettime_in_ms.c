/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime_in_ms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:39:08 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:12:17 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <sys/time.h>

int64_t	gettime_in_ms(void)
{
	struct timeval	tv;
	int64_t			res;

	gettimeofday(&tv, NULL);
	res = 1000 * (size_t)tv.tv_sec + (size_t)tv.tv_usec / 1000;
	return (res);
}
