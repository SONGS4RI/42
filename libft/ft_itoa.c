/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:03:38 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/17 16:29:28 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long int nbr)
{
	int		len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

long int	ft_abs(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

char	*ft_itoa(int n)
{
	int		len;
	int		minus;
	char	*res;

	minus = 0;
	if (n < 0)
		minus = 1;
	len = ft_len(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (0);
	res[len] = '\0';
	while (--len >= 0)
	{
		res[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
	}
	if (minus)
		res[0] = '-';
	return (res);
}

