/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:42:08 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 21:42:42 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./func.h"

int	check_max_colup(t_sky bd)
{
	int	max;
	int	r;
	int	c;
	int	cnt;

	c = -1;
	while (++c < 4)
	{
		r = 0;
		max = bd.sq[r][c];
		cnt = 1;
		while (++r < 4)
		{
			if (max < bd.sq[r][c])
			{
				max = bd.sq[r][c];
				cnt++;
			}
		}
		if (cnt != bd.chk[c])
			return (1);
	}
	return (0);
}

int	check_max_coldown(t_sky bd)
{
	int	max;
	int	r;
	int	c;
	int	cnt;

	c = -1;
	while (++c < 4)
	{
		r = 3;
		max = bd.sq[r][c];
		cnt = 1;
		while (--r >= 0)
		{
			if (max < bd.sq[r][c])
			{
				max = bd.sq[r][c];
				cnt++;
			}
		}
		if (cnt != bd.chk[c + 4])
			return (1);
	}
	return (0);
}

int	check_max_rowleft(t_sky bd)
{
	int	max;
	int	r;
	int	c;
	int	cnt;

	r = -1;
	while (++r < 4)
	{
		c = 0;
		max = bd.sq[r][c];
		cnt = 1;
		while (c++ < 4)
		{
			if (max < bd.sq[r][c])
			{
				max = bd.sq[r][c];
				cnt++;
			}
		}
		if (cnt != bd.chk[r + 8])
			return (1);
	}
	return (0);
}

int	check_max_rowright(t_sky bd)
{
	int	max;
	int	r;
	int	c;
	int	cnt;

	r = -1;
	while (++r < 4)
	{
		c = 3;
		max = bd.sq[r][c];
		cnt = 1;
		while (--c >= 0)
		{
			if (max < bd.sq[r][c])
			{
				max = bd.sq[r][c];
				cnt++;
			}
		}
		if (cnt != bd.chk[r + 12])
			return (1);
	}
	return (0);
}

int	check_final(t_sky bd)
{
	int	i;

	i = 0;
	i += check_max_colup(bd);
	i += check_max_coldown(bd);
	i += check_max_rowleft(bd);
	i += check_max_rowright(bd);
	return (i);
}
