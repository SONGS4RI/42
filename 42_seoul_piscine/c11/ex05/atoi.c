/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:54:14 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/12 19:02:05 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	atoi(char *str)
{
	int	num;
	int	minus;

	num = 0;
	minus = 1;
	while (*str <= ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num * minus);
}
