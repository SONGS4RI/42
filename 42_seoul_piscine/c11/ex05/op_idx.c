/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_idx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:33:22 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/12 20:40:03 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	op_idx(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 1)
		return (-1);
	if (*str == '+')
		return (0);
	else if (*str == '-')
		return (1);
	else if (*str == '/')
		return (2);
	else if (*str == '*')
		return (3);
	else if (*str == '%')
		return (4);
	return (-1);
}
