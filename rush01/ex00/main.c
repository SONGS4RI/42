/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:22:49 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 20:18:06 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct t_Sky
{
	int	sq[4][4];
	int	chk[16];
	int	init[4][4];
	int	r;
	int	c;
}	t_Sky;

t_Sky	init_up(t_Sky bd, int col)
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

t_Sky	init_down(t_Sky bd, int col)
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

t_Sky	init_left(t_Sky bd, int row)
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

t_Sky	init_right(t_Sky bd, int row)
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

t_Sky	zero_board(t_Sky bd)
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

t_Sky	init_board(t_Sky bd)
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

void	print_board(t_Sky bd, int n)
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

int	check_max_colup(t_Sky bd)
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

int	check_max_coldown(t_Sky bd)
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

int	check_max_rowleft(t_Sky bd)
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

int	check_max_rowright(t_Sky bd)
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

int	check_final(t_Sky bd)
{
	int	i;

	i = 0;
	i += check_max_colup(bd);
	i += check_max_coldown(bd);
	i += check_max_rowleft(bd);
	i += check_max_rowright(bd);
	return (i);
}

int	check_col_dup(t_Sky bd)
{
	int	r;

	r = -1;
	while (++r < 4)
		if (bd.sq[bd.r][bd.c] == bd.sq[r][bd.c] && r != bd.r)
			return (1);
	return (0);
}

int	check_row_dup(t_Sky bd)
{
	int	c;

	c = -1;
	while (++c < bd.c)
		if (bd.sq[bd.r][bd.c] == bd.sq[bd.r][c] && c != bd.c)
			return (1);
	return (0);
}

int	check_board(t_Sky bd)
{
	int	i;

	i = 0;
	i += check_row_dup(bd);
	i += check_col_dup(bd);
	return (i);
}

void	board_board(t_Sky bd, int n, int *flag);

t_Sky	fill_board(t_Sky *bd, int n, int *flag)
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

void	board_board(t_Sky bd, int n, int *flag)
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

int	get_chk(t_Sky *bd, char *s)
{
	int		i;
	int		j;
	int		cnt;
	char	*str;

	cnt = 0;
	str = s;
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			bd->chk[++j] = str[i] - '0';
			cnt++;
		}
		else if ((str[i] >= '5' && str[i] <= '9') || str[i] == '0')
			return (0);
	}
	if (cnt == 16)
		return (1);
	else
		return (0);
}

void	print_error(void)
{
	write(1, "Error", 5);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		n;
	int		flag;
	t_Sky	bd;

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
