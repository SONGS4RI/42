/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:17:46 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/10 16:50:14 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;
	int	*pt;

	len = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	pt = (int *)malloc(sizeof(int) * len);
	if (pt == NULL)
		return (-1);
	i = -1;
	while (++i < len)
		pt[i] = min + i;
	*range = pt;
	return (len);
}
