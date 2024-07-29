/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:44:18 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 22:04:31 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./func.h"
#include "./init.h"

t_sky	zero_board(t_sky bd)
{
	int	r;
	int	c;

	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			bd.sq[r][c] = 0;
			bd.init[r][c] = 0;
		}
	}
	return (bd);
}

t_sky	init_board(t_sky bd)
{
	int	i;
	int	row;
	int	col;
	int	chk;

	i = -1;
	bd = zero_board(bd);
	while (++i < 4 * 4)
	{
		row = i / 4;
		col = i % 4;
		chk = bd.chk[i];
		if (chk == 4)
		{
			if (row == 0)
				bd = init_up(bd, col);
			else if (row == 1)
				bd = init_down(bd, col);
			else if (row == 2)
				bd = init_left(bd, col);
			else
				bd = init_right(bd, col);
		}
	}
	return (bd);
}
