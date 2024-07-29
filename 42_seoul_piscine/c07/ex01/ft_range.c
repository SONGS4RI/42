/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:36:59 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/10 16:33:15 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*pt;
	int	i;

	len = max - min;
	if (min >= max)
		return (NULL);
	pt = (int *)malloc(sizeof(int) * len);
	if (pt == NULL)
		return (0);
	i = -1;
	while (++i < len)
		pt[i] = min + i;
	return (pt);
}
