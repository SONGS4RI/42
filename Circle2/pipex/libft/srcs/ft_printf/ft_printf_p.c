/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:30:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/10 20:18:42 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_putptr(size_t ptr, size_t *len)
{
	char	c;

	if (ptr >= 16)
	{
		if (ft_putptr(ptr / 16, len))
			return (-1);
		if (ft_putptr(ptr % 16, len))
			return (-1);
	}
	else
	{
		if (ptr < 10)
			c = '0' + ptr;
		else
			c = ptr - 10 + 'a';
		if (write(1, &c, 1) == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	ft_printf_p(void *ptr)
{
	size_t	len;

	len = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2;
	if (ft_putptr((size_t)ptr, &len) == -1)
		return (-1);
	return (len);
}
