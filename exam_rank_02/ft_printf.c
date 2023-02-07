/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:57:22 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/07 15:25:01 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	print_s(char *s, int *cnt)
{
	int	idx;

	idx = -1;
	while (s[++idx])
		write(1, s + idx, 1);
	*cnt += idx;
}



void	print_d(long long n, int *cnt)
{
	char	c;

	if (n < 0)
	{
		n *= -1;
		*cnt += write(1, "-", 1);
	}
	if (n > 9)
		print_d(n / 10, cnt);
	c = n % 10 + '0';
	*cnt += write(1, &c, 1);
}

void	print_x(unsigned int n, int *cnt)
{
	char		c;
	static char	s[17] = "0123456789abcdef";

	if (n > 15)
		print_x(n / 16, cnt);
	*cnt += write(1, s + n % 16, 1);
}


void	parse(char *s, va_list *ap, int *cnt)
{
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 's')
				print_s(va_arg(*ap, char *), cnt);
			else if (*s == 'd')
				print_d(va_arg(*ap, int), cnt);
			else if (*s == 'x')
				print_x(va_arg(*ap, unsigned int), cnt);
		}
		else
			*cnt += write(1, s, 1);
		s++;
	}
}

int	ft_printf(char *s, ...)
{
	va_list		ap;
	int			cnt;

	cnt = 0;
	va_start(ap, s);
	parse(s, &ap, &cnt);
	va_end(ap);
	return (cnt);
}

#include <stdio.h>
int	main()
{
	int n = ft_printf("%x %s %d\n", 223, "good", -101);
	printf("%d\n",n);
}