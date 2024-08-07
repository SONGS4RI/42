/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 07:24:28 by jahlee            #+#    #+#             */
/*   Updated: 2022/08/31 13:56:03 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
			str++;
		else if (*str >= 97 && *str <= 122)
			str++;
		else
			return (0);
	}
	return (1);
}
