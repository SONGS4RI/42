/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:27:18 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/03 16:02:41 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned int nbr, char *s, size_t *len)
{
	char	c;

	if (nbr >= 10)
	{
		if (ft_putnbr_base(nbr / 10, s, len))
			return (-1);
		if (ft_putnbr_base(nbr % 10, s, len))
			return (-1);
	}
	else
	{
		c = '0' + nbr;
		if (write(1, &c, 1) == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	ft_printf_u(unsigned int nbr)
{
	size_t	len;

	len = 0;
	if (ft_putnbr_base(nbr, "0123456789", &len))
		return (-1);
	return (len);
}
