/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:12:53 by user              #+#    #+#             */
/*   Updated: 2022/09/06 11:15:18 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen2(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

int	check(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen2(str) <= 1)
		return (0);
	while (str[i])
	{
		j = i + 1;
		if (str[i] == '+' || str[i] == '-')
			return (0);
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	func(long long nbr, char *base, long long len)
{
	long long	c;

	c = nbr % len;
	if (nbr == 0)
		return ;
	func(nbr / len, base, len);
	write(1, &base[c], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	num;
	long long	len;

	num = (long long)nbr;
	if (check(base))
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num *= -1;
		}
		if (num == 0)
			write(1, base, 1);
		len = ft_strlen2(base);
		func(num, base, len);
	}
	else
		return ;
}
