/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:07:44 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/06 17:32:52 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char		*s;
	static int	arr[128] = {0,};

	if (argc == 3)
	{
		s = argv[2];
		while (*s)
		{
			arr[*s]++;
			s++;
		}
		s = argv[1];
		while (*s)
		{
			if (arr[*s])
			{
				write(1, s, 1);
				arr[*s] = 0;
			}
			s++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
