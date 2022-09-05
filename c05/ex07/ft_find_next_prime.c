/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:50:09 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/06 08:53:21 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	flag;

	while (1)
	{
		i = 2;
		flag = 1;
		while (i <= nb / i)
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
