/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcrakeha <hcrakeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:55:07 by hcrakeha          #+#    #+#             */
/*   Updated: 2022/01/26 19:12:17 by hcrakeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int64_t	ft_atol(const char *str)
{
	int		minus;
	int64_t	result;

	result = 0;
	minus = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		minus *= -1;
		str++;
	}
	else if (*str == '+')
		++str;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * minus);
}
