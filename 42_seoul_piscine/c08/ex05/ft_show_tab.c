/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:10:46 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/12 12:18:38 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_putnum(int num)
{
	int	c;

	c = num % 10 + '0';
	if (num > 0)
	{
		ft_putnum(num / 10);
		write(1, &c, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	if (!par)
		return ;
	while (par->str)
	{
		ft_putstr(par->str);
		if (par->size == 0)
			write(1, "0", 1);
		else
			ft_putnum(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		par++;
	}
}
