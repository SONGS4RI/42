/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_origin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:22:49 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 09:35:36 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct _Sky
{
	int	sq[4][4];
	int	chk[16];
	int	r;
	int	c;
	int	size;
}	Sky;

int check_max_up(Sky bd)
{
	int	max;
	int	r;
	int	c;
	int	cnt;

	r = 0;
	while (++r < bd.size)
	{
		c = 0;
		max = bd.sq[r][c];
		cnt = 1;
		while (++c < bd.size)
		{
			if (max < bd.sq[r][c])
			{
				max = bd.sq[r][c];
				cnt++;
			}
		}
		if (cnt != bd.chk[r])
			return (1);
	}
	return (0);
}
	
Sky	init_up(Sky bd, int col, int chk)
{
	int	i;

	i = -1;
	if (chk == bd.size)
	{
		while (++i < bd.size)
			bd.sq[i][col] = i + 1;
	}
	return (bd);
}

Sky	init_down(Sky bd, int col, int chk)
{
	int	i;

	i = -1;
	if (chk == 4)
	{
		while (++i < bd.size)
			bd.sq[i][col] = bd.size - i;
	}
	return (bd);
}

Sky	init_left(Sky bd, int row, int chk)
{
	int	i;

	i = -1;
	if (chk == bd.size)
	{
		while (++i < bd.size)
			bd.sq[row][i] = i + 1;
	}
	return (bd);
}

Sky	init_right(Sky bd, int row, int chk)
{
	int	i;

	i = -1;
	if (chk == bd.size)
	{
		while (++i <bd.size)
			bd.sq[row][i] = bd.size - i;
	}
	return (bd);
}

Sky	zero_board(Sky bd)
{
	int	r;
	int	c;

	r = -1;
	while (++r < bd.size)
	{
		c = -1;
		while (++c < bd.size)
			bd.sq[r][c] = 0;
	}
	return (bd);
}

//chk/i > 1 up 2 down 3 left 4 rigit
//chk%i > 0 1 2 3 idx
Sky init_board(Sky bd)
{
	int	i;
	int	nn;
	int	where;
	int	temp;
	int	chk;

	i = -1;
	nn = bd.size * bd.size;
	bd = zero_board(bd);
	while (++i < nn)
	{
		where = i / bd.size;
		temp = i % bd.size;
		chk = bd.chk[i];
		if (chk == bd.size)
		{
			if (where == 0)
				bd = init_up(bd, temp, chk);
			else if (where == 1)
				bd = init_down(bd, temp, chk);
			else if (where == 2)
				bd = init_left(bd, temp, chk);
			else
				bd = init_right(bd, temp, chk);
		}
	}
	return (bd);

}	
void print_board(Sky bd, int n, int *cnt)
{
	int	r;
	int	c;
	char ch;

	r = -1;
	while (++r < n)
	{
		c = -1;
		while (++c < n)
		{
			ch = bd.sq[r][c] + '0';
			write(1, &ch, 1);
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
	*cnt += 1;
}

int	check_row_dup(Sky bd)
{
	int	r;
	r = -1;
	while (++r < bd.r)
		if (bd.sq[bd.r][bd.c] == bd.sq[r][bd.c])
			return (1);
	return (0);
}

int	check_col_dup(Sky bd)
{
	int	c;
	c = -1;
	while (++c < bd.c)
		if (bd.sq[bd.r][bd.c] == bd.sq[bd.r][c])
			return (1);
	return (0);
}
int	check_final(Sky bd)
{
	int	i;

	i = 0;
	i += check_max_up(bd);
	return (i);
	
}
int	check_board(Sky bd)
{
	int	i;

	i = 0;
	i += check_row_dup(bd);
	i += check_col_dup(bd);
	return (i);
}

void	board_board(Sky bd, int n, int *cnt);
Sky	fill_board(Sky *bd, int n, int *cnt)
{
	if (bd->r == n - 1 && bd->c == n - 1 && !(check_final(*bd)))
	{
		print_board(*bd, n, cnt);
		return (*bd);
	}
	else if (bd->c < n - 1)
	{
		bd->c++;
		board_board(*bd, n, cnt);
		bd->c--;
	}
	else if (bd->c == n - 1)
	{
		bd->c = 0;
		bd->r++;
		board_board(*bd, n, cnt);
		bd->c = n - 1;
		bd->r--;	
	}

	return (*bd);
}

//bd.sq[row][col]
void	board_board(Sky bd, int n, int *cnt)
{
	int	i;

	if (bd.r >= bd.size || bd.c >= bd.size)
		return ;
	if (bd.sq[bd.r][bd.c] > 0)
		fill_board(&bd, n, cnt);	
	else
	{
		i = 0;
		while (++i <= n)
		{
			bd.sq[bd.r][bd.c] = i;
			if (!(check_board(bd)))
				fill_board(&bd, n, cnt);
		}
	}
}

int	get_chk(Sky *bd, char *av)
{
	int	i;

	i = -1;
	while (av[++i] && i >= 0)
	{
		if (!(i % 2) && av[i] >= '1' && av[i] <= bd->size + '0')
			bd->chk[i/2] = (int)(av[i] - '0');
		else if (i % 2 && av[i] == ' ')
			continue;
		else
			return (1);
	}
	return (0);
}
int get_chk2(Sky *bd, char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (av[i] >= '1' && av[i] <= bd->size + '0')
			bd->chk[i] = (int)(av[i] - '0');
		else
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	n;
	Sky bd;
	int	cnt[1];
	bd.c = 0;
	bd.r = 0;
	*cnt = 0;
	n  = 4;
	bd.size = 4;
	if (ac == 2)
	{
		if (get_chk(&bd, av[1]))
			return (1);
	}
	else if (ac == 17)
	{
		if (get_chk2(&bd, av))
			return (1);
	}
	else
		return (1);
	bd = init_board(bd);
	board_board(bd, n, cnt);
}
