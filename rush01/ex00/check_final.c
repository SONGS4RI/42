/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_final.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:41:11 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 21:41:36 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./func.h"

int	check_col_dup(t_sky bd)
{
	int	r;

	r = -1;
	while (++r < 4)
		if (bd.sq[bd.r][bd.c] == bd.sq[r][bd.c] && r != bd.r)
			return (1);
	return (0);
}

int	check_row_dup(t_sky bd)
{
	int	c;

	c = -1;
	while (++c < bd.c)
		if (bd.sq[bd.r][bd.c] == bd.sq[bd.r][c] && c != bd.c)
			return (1);
	return (0);
}

int	check_board(t_sky bd)
{
	int	i;

	i = 0;
	i += check_row_dup(bd);
	i += check_col_dup(bd);
	return (i);
}
