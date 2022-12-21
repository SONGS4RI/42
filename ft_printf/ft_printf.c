/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:30:45 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/21 22:57:25 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	parse_format(va_list ap, char *format)
{
	int		result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 0)
				break ;
			/*
            		서식 문자에 따라 맞는 값을 출력
            		*/
		}
		else
			result += ft_putchar(*format); // 일반 문자를 출력
		format++;
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int			result;
	va_list		ap;

	result = 0;
	va_start(ap, format);
	result = parse_format(ap, (char *)format);
	va_end(ap);
	return (result);
}

int main()
{
	ft_printf("abc%c",'d');
}