/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:22:49 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 21:35:13 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./header.h"

int	main(int argc, char **argv)
{
	int		n;
	int		flag;
	t_sky	bd;

	bd.c = 0;
	bd.r = 0;
	n = 4;
	flag = 0;
	if (argc == 2)
	{
		if (get_chk(&bd, argv[1]))
		{
			bd = init_board(bd);
			board_board(bd, n, &flag);
			if (flag == 0)
				print_error();
		}
		else
			print_error();
	}
	else
		print_error();
	return (0);
}
