/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:51:50 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/11 20:24:10 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strcpy(char *str)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(ft_strlen(str) + 1);
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*t;
	int			i;

	if (ac < 0)
		ac = 0;
	t = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!t)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
			t[i].size = ft_strlen(av[i]);
			t[i].str = av[i];
			t[i].copy = ft_strcpy(av[i]);
	}
	t[i].str = 0;
	return (t);
}
