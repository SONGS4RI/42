/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:33:38 by jahlee            #+#    #+#             */
/*   Updated: 2022/08/31 20:40:10 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	flag;

	flag = 1;
	while (*str)
	{
		if (*str < ' ' || *str == 127)
		{
			flag = 0;
			break ;
		}
		str++;
	}
	return (flag);
}
