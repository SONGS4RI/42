/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:29:14 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/12 20:59:20 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*pt;

	pt = (int *)malloc(sizeof(int) * length);
	if (!pt)
		return (0);
	i = -1;
	while (++i < length)
		pt[i] = f(tab[i]);
	return (pt);
}
