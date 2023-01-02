/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:27:18 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/02 17:32:38 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned int nbr, char *s, size_t *len)
{
	char	c;

	if (nbr >= 10)
	{
		ft_putnbr_base(nbr / 10, s, len);
		ft_putnbr_base(nbr % 10, s, len);
	}
	else
	{
			c = '0' + nbr;
			*len += write(1, &c, 1);
	}
}

int	ft_printf_u(unsigned int nbr)
{
	size_t	len;

	len = 0;
	ft_putnbr_base(nbr, "0123456789", &len);
	return (len);
}
