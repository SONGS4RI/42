/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:30:23 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/28 15:28:17 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(size_t ptr, size_t *len)
{
	char	c;

	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, len);
		ft_putptr(ptr % 16, len);
	}
	else
	{
		if (ptr < 10)
		{
			c = '0' + ptr;
			*len += write(1, &c, 1);
		}
		else
		{
			c = ptr - 10 + 'a';
			*len += write(1, &c, 1);
		}
	}
}

int	ft_printf_p(void *ptr)
{
	size_t	len;

	len = 0;
	len += write(1, "0x", 2);
	ft_putptr((size_t)ptr, &len);
	return (len);
}
