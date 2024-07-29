/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:53:42 by jahlee            #+#    #+#             */
/*   Updated: 2022/08/30 15:23:52 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;
	int	idx;

	i = 0;
	while (i < size)
	{
		min = 2147483647;
		j = i;
		while (j < size)
		{
			if (tab[j] < min)
			{
				min = tab[j];
				idx = j;
			}
			j++;
		}
		swap(tab + i, tab + idx);
		i++;
	}
}
