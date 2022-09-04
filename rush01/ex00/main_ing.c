/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:22:49 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 13:27:49 by jahlee           ###   ########.fr       */
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


////////////////////////////////////       초기화부분          ///////////////////////////////////////////////////
	
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
	if (chk == bd.size)
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
	//int	nn;
	int	row;
	int	col;
	int	chk;

	i = -1;
	//nn = bd.size * bd.size;
	bd = zero_board(bd);
	while (++i < bd.size * bd.size)
	{
		row = i / bd.size;
		col = i % bd.size;
		chk = bd.chk[i];
		if (chk == bd.size) // 4일때 초기화
		{
			if (row == 0)
				bd = init_up(bd, col, chk);
			else if (row == 1)
				bd = init_down(bd, col, chk);
			else if (row == 2)
				bd = init_left(bd, col, chk);
			else
				bd = init_right(bd, col, chk);
		}
	}
	return (bd);

}	
////////////////////////////////////      print_board       ///////////////////////////////////////////////////
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
////////////////////////////////////       check_final          ///////////////////////////////////////////////////

int check_max_up(Sky bd)
{
	int	max;
	int	r;
	int	c;
	int	cnt;

	r = -1; 									// r = 0 -> r = -1
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

int	check_final(Sky bd)
{
	int	i;

	i = 0;
	i += check_max_up(bd);
	return (i);
	
}
////////////////////////////////////       check_board          ///////////////////////////////////////////////////

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

int	check_board(Sky bd)
{
	int	i;

	i = 0;
	i += check_row_dup(bd);
	i += check_col_dup(bd);
	return (i);
}

////////////////////////////////////       fill_board         ///////////////////////////////////////////////////

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
	else if (bd->c == n - 1) // 3열에 왔을때 
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
void	board_board(Sky bd, int n, int *cnt)  // ?? 
{
	int	i;
	
	if (bd.r >= bd.size || bd.c >= bd.size)
		return ;
	if (bd.sq[bd.r][bd.c] > 0)
		fill_board(&bd, n, cnt);	
	else
	{
		i = 0;
		while (++i <= n) // n=4
		{
			bd.sq[bd.r][bd.c] = i;
			if (!(check_board(bd)))
				fill_board(&bd, n, cnt);
		}
	}
}
////////////////////////////////////        *char 입력값 구조체에 int 배열로 저장          ///////////////////////////////////////////////////

void	get_chk(Sky *bd, char *s)  // 수정함
{
	int	i;
	int j;
	char *str;
	
	str = s;
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] >= '1' && str[i] <= '4')
			bd->chk[++j] = str[i] - '0';
	}
	return ;
}
////////////////////////////////////       main          ///////////////////////////////////////////////////

int	main()
{
	int	n;
	Sky bd;
	int	cnt[1];
	char str[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 "; // 
	
	bd.c = 0;
	bd.r = 0;
	*cnt = 0;
	n  = 4;
	bd.size = 4;

	;
	// if (argc == 2)
	// {
		
		get_chk(&bd, str);
		bd = init_board(bd);
		board_board(bd, n, cnt);
	// }
	// else write(1,"Wrong",6);
	return (0);
}
