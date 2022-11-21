/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:22:21 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/21 13:19:13 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	sign;
	long	nbr;
	size_t	i;

	sign = 1;
	nbr = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + sign * (str[i] - '0');
		i++;
	}
	return (nbr);
}
