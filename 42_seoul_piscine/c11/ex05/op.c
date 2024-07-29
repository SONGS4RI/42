/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:28:14 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/13 09:37:55 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	myplus(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	myminus(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	mydev(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	ft_putnbr(a / b);
	write(1, "\n", 1);
}

void	mymul(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	mymod(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	ft_putnbr(a % b);
	write(1, "\n", 1);
}
