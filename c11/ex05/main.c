/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:47:45 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/12 19:03:14 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	do_op(int a, int b, void (*f)(int, int))
{
	f(a, b);
}

int	main(int ac, char **av)
{
	void	*arr[5];
	int		op_num;

	arr[0] = myplus;
	arr[1] = myminus;
	arr[2] = mydev;
	arr[3] = mymul;
	arr[4] = mymod;
	if (ac == 4)
	{
		op_num = op_idx(av[2]);
		if (op_num == -1)
			write(1, "0\n", 2);
		else
			do_op(atoi(av[1]), atoi(av[3]), arr[op_num]);
	}
	else
		return (0);
}
