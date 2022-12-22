/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:28:35 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/22 18:28:36 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf_hex(unsigned int nbr, const char type)
{
	size_t	len;

	len = 0;
	if (type == 'X')
		len = ft_putnbr_base(nbr, "0123456789ABCDEF");
	else
		len = ft_putnbr_base(nbr, "0123456789abcdef");
	return (len);
}