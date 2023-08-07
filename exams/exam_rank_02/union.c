/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:35:49 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/06 17:42:15 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char		*s;
	static int	arr[128] = {0,};

	if (argc == 3)
	{
		s = argv[1];
		while (*s)
		{
			if (!arr[*s])
			{
				write(1, s, 1);
				arr[*s] = 1;
			}
			s++;
		}
		s = argv[2];
		while (*s)
		{
			if (!arr[*s])
			{
				write(1, s, 1);
				arr[*s] = 1;
			}
			s++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
