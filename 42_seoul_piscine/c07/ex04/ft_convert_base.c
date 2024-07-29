/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:15:32 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/10 19:51:19 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_strlen1(char *str);
int	check1(char *str);

int	res_len(long long res, long long len_base_to)
{
	int	cnt;

	cnt = 1;
	while (res / len_base_to > 0)
	{
		res /= len_base_to;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa_base(long long res, char *base_to, int minus)
{
	long long	len_base_to;
	char		*pt;
	int			i;

	len_base_to = ft_strlen1(base_to);
	pt = (char *)malloc(res_len(res, len_base_to) + 1 + minus);
	if (pt == NULL)
		return (0);
	if (minus)
		pt[0] = '-';
	i = res_len(res, len_base_to) + minus;
	pt[i--] = '\0';
	while (i >= minus)
	{
		pt[i] = base_to[res % len_base_to];
		res /= len_base_to;
		i--;
	}
	return (pt);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	res;
	char		*pt;
	int			minus;

	minus = 0;
	if (nbr == 0)
		return (0);
	if (!check1(base_to) || !check1(base_from))
		return (NULL);
	res = (long long)ft_atoi_base(nbr, base_from);
	if (res < 0)
	{
		res *= -1;
		minus = 1;
	}
	pt = ft_itoa_base(res, base_to, minus);
	return (pt);
}
