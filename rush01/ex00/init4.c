/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:45:33 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 21:46:43 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./func.h"

t_sky	init_up(t_sky bd, int col)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		bd.sq[i][col] = i + 1;
		bd.init[i][col] = 1;
	}
	return (bd);
}

t_sky	init_down(t_sky bd, int col)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		bd.sq[i][col] = 4 - i;
		bd.init[i][col] = 1;
	}
	return (bd);
}

t_sky	init_left(t_sky bd, int row)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		bd.sq[row][i] = i + 1;
		bd.init[row][i] = 1;
	}
	return (bd);
}

t_sky	init_right(t_sky bd, int row)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		bd.sq[row][i] = 4 - i;
		bd.init[row][i] = 1;
	}
	return (bd);
}
