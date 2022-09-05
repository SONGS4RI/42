/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:47:58 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/05 15:28:49 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen1(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

int	check1(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen1(str) <= 1)
		return (0);
	while (str[i])
	{
		j = i + 1;
		if (str[i] == '+' || str[i] == '-')
			return (0);
		if ((*str >= 9 && *str <= 13) || *str == ' ')
			return (0);
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	func(char *s, char *base, int *res, int base_len)
{
	int	minus;
	int	i;

	minus = 1;
	while (*s == '-' || *s == '+' || (*s >= 9 && *s <= 13) || *s == ' ')
	{
		if (*s == '-')
			minus *= -1;
		s++;
	}
	while (*s)
	{
		i = -1;
		while (++i <= base_len)
		{
			if (base[i] == '\0')
				return ;
			if (*s == base[i])
			{
				*res = (*res) * base_len + minus * i;
				break ;
			}
		}
		s++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	res;

	res = 0;
	base_len = ft_strlen1(base);
	if (check1(base))
	{
		func(str, base, &res, base_len);
		return (res);
	}
	else
		return (0);
}
