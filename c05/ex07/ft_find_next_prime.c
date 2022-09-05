/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:50:09 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/05 18:52:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	i;
	int	flag;

	while (1)
	{
		i = 2;
		flag = 1;
		while (i * i <= nb)
		{
			if (nb % i == 0)
			{
				flag = 0;
				break ;
			}
			i++;
		}
		if (flag == 0)
			nb++;
		else
			return (nb);
	}
}

int main()
{
	printf("%d\n",ft_find_next_prime(2147483647));
}