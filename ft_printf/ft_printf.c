/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:30:45 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/22 18:29:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	check_type(const char c, va_list *list)
{
	if (c == 'c')
		return (ft_printf_c(va_arg(*list, int)));
	else if (c == 's')
		return (ft_printf_s(va_arg(*list, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_nbr(va_arg(*list, int)));
	else if (c == 'u')
		return (ft_printf_u(va_arg(*list, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printf_hex(va_arg(*list, unsigned int), c));
	else if (c == 'p')
		return (ft_printf_ptr(va_arg(*list, unsigned long long)));
	else if (c == '%')
		return (ft_printf_c('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	int			idx;
	va_list		ap;

	va_start(ap, format);
	len = 0;
	idx = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			len += check_type(format[idx + 1], &ap);
			idx++;
		}
		else
			len += ft_printf_char(format[idx]);
		idx++;
	}
	va_end(ap);
	return (len);
}