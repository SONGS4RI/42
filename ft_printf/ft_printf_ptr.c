/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:30:23 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/22 18:30:24 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_putptr(unsigned long long ptr, size_t *len)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, len);
		ft_putptr(ptr % 16, len);
	}
	else
	{
		if (ptr < 10)
			*len += ft_putchar_fd('0' + ptr, 1);
		else
			*len += ft_putchar_fd(ptr - 10 + 'a', 1);
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	size_t	len;

	len = 0;
	len += ft_putstr_fd("0x", 1);
	ft_putptr(ptr, &len);
	return (len);
}