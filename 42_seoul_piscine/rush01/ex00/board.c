/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:11:20 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 22:11:27 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./func.h"
#include "./board.h"

void	board_board(t_sky bd, int n, int *flag);

void	print_board(t_sky bd, int n);

t_sky	fill_board(t_sky *bd, int n, int *flag)
{
	int	*p;

	p = flag;
	if (bd->r == n - 1 && bd->c == n - 1 && !(check_final(*bd)))
	{
		print_board(*bd, n);
		*p = 1;
		return (*bd);
	}
	else if (bd->c < n - 1)
	{
		bd->c++;
		board_board(*bd, n, p);
		bd->c--;
	}
	else if (bd->c == n - 1)
	{
		bd->c = 0;
		bd->r++;
		board_board(*bd, n, p);
		bd->c = n - 1;
		bd->r--;
	}
	return (*bd);
}

void	board_board(t_sky bd, int n, int *flag)
{
	int	i;
	int	*p;

	p = flag;
	if (bd.r >= 4 || bd.c >= 4)
	{
		return ;
	}
	if (bd.init[bd.r][bd.c] == 1)
		fill_board(&bd, n, p);
	else
	{
		i = 0;
		while (++i <= n)
		{
			bd.sq[bd.r][bd.c] = i;
			if (!(check_board(bd)))
				fill_board(&bd, n, p);
		}
	}
}

void	print_board(t_sky bd, int n)
{
	int		r;
	int		c;
	char	ch;

	r = -1;
	while (++r < n)
	{
		c = -1;
		while (++c < n)
		{
			ch = bd.sq[r][c] + '0';
			write(1, &ch, 1);
			if (c < 3)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	if (r < 3)
		write(1, "\n", 1);
}
