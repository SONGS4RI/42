/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:23:46 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/01 12:04:29 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	alphanum(char c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (*str >= 97 && *str <= 122 && flag == 0)
		{
			flag = 1;
			*str -= 32;
		}
		else if (*str >= 65 && *str <= 90 && flag == 1)
		{
			flag = 1;
			*str += 32;
		}
		else if (alphanum(*str))
			flag = 1;
		else
			flag = 0;
		str++;
		i++;
	}
	return (str - i);
}
