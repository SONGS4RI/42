/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:50:09 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/05 16:18:03 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	flag;

	i = 2;
	while (1)
	{
		flag = 1;
		while (i < nb / 2)
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
