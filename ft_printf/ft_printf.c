/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:30:45 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/28 15:09:21 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char c, va_list *ap)
{
	if (c == 'c')
		return (ft_printf_c(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_printf_s(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_di(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_printf_u(va_arg(*ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printf_hex(va_arg(*ap, unsigned int), c));
	else if (c == 'p')
		return (ft_printf_p(va_arg(*ap, void *)));
	else if (c == '%')
		return (ft_printf_c('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int			cnt;
	int			idx;
	int			len;
	va_list		ap;

	va_start(ap, format);
	cnt = 0;
	idx = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			len = check_type(format[++idx], &ap);
			if (len == -1)
				return (-1);
			cnt += len;
		}
		else
			cnt += ft_printf_c(format[idx]);
		idx++;
	}
	va_end(ap);
	return (cnt);
}
