/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:03:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/10 20:16:21 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_len(int nbr)
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

static long long	ft_abs(long long nbr)
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
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
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
