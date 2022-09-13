/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/12 14:37:55 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			if (flag == 1)
				return (0);
			flag = -1;
		}
		else if (f(tab[i], tab[i + 1]) > 0)
		{
			if (flag == -1)
				return (0);
			flag = 1;
		}			
	}
	return (1);
}
