/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:28:35 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/10 20:18:40 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_putnbr_base(unsigned int nbr, char *s, size_t *len)
{
	char	c;

	if (nbr >= 16)
	{
		if (ft_putnbr_base(nbr / 16, s, len))
			return (-1);
		if (ft_putnbr_base(nbr % 16, s, len))
			return (-1);
	}
	else
	{
		if (nbr < 10)
			c = '0' + nbr;
		else
			c = nbr - 10 + s[10];
		if (write(1, &c, 1) == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	ft_printf_hex(unsigned int nbr, const char type)
{
	size_t	len;

	len = 0;
	if (type == 'X' && !ft_putnbr_base(nbr, "0123456789ABCDEF", &len))
		return (len);
	else if (type == 'x' && !ft_putnbr_base(nbr, "0123456789abcdef", &len))
		return (len);
	return (-1);
}
