/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:28:26 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/12 19:01:31 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnbr(int nbr)
{
	long long	num;
	int			c;

	num = (long long)nbr;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	c = num % 10 + '0';
	if (num / 10 > 0)
		ft_putnbr(num / 10);
	write(1, &c, 1);
}
