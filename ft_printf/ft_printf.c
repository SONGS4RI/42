/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:30:45 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/20 21:23:49 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static	void	what_conversion(char c, va_list *ap)
{
	if (c == 'c')
		ft_printf_c(c, ap);
	// else if (c == 's')
	// 	ft_printf_s();
	// else if (c == 'p')
	// 	ft_printf_p();
	// else if (c == 'd')
	// 	ft_printf_d();
	// else if (c == 'i')
	// 	ft_printf_i();
	// else if (c == 'u')
	// 	ft_printf_u();
	// else if (c == 'x')
	// 	ft_printf_x();
	// else if (c == 'X')
	// 	ft_printf_X();
	// else if (c == '%')
	// 	ft_printf_percent();
}

int	ft_printf(const	char *s, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
			what_conversion(s[++i], &ap);
		else
			write(1, s + i, 1);
		i++;
	}
	return (0);
}

int main()
{
	ft_printf("abc%c",'d');
}