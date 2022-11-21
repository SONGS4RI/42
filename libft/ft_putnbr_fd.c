/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:09:25 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/21 13:44:22 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_abs(long long nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;
	char		c;

	if (n < 0)
		write(fd, "-", 1);
	num = ft_abs(n);
	if (num / 10)
		ft_putnbr_fd(num / 10, fd);
	c = '0' + num % 10;
	write(fd, &c, 1);
}
