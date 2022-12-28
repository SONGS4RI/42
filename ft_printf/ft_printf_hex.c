/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:28:35 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/28 15:28:16 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned int nbr, char *s, size_t *len)
{
	char	c;

	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, s, len);
		ft_putnbr_base(nbr % 16, s, len);
	}
	else
	{
		if (nbr < 10)
		{
			c = '0' + nbr;
			*len += write(1, &c, 1);
		}
		else
		{
			c = nbr - 10 + s[10];
			*len += write(1, &c, 1);
		}
	}
}

int	ft_printf_hex(unsigned int nbr, const char type)
{
	size_t	len;

	len = 0;
	if (type == 'X')
		ft_putnbr_base(nbr, "0123456789ABCDEF", &len);
	else
		ft_putnbr_base(nbr, "0123456789abcdef", &len);
	return (len);
}
