/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:25:12 by jahlee            #+#    #+#             */
/*   Updated: 2022/08/31 20:53:22 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexadecimal(unsigned char num)
{
	unsigned char	hex1;
	unsigned char	hex2;

	if ((num / 16) < 10)
		hex1 = num / 16 + '0';
	else
		hex1 = num / 16 + 'W';
	num %= 16;
	if ((num % 16) < 10)
		hex2 = num % 16 + '0';
	else
		hex2 = num % 16 + 'W';
	write(1, &hex1, 1);
	write(1, &hex2, 1);
}

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] <= 31 || str[i] >= 127)
		{
			write(1, "\\", 1);
			hexadecimal(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
