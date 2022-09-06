/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 08:55:51 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/06 10:15:56 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_str(int *board)
{
	int	i;

	i = 0;
	while (i < 10)
		write(1,&board[i],1);
	write(1,"\n",1);	
}

int	check(int *board, int i)
{
	int	j;
	
	j = -1;
	while (++j < i)
	{
		if(board[i] == board[j])
			return (0);
		else if (board[i] == board[j] + (i - j))
			return (0);
		else if (board[i] == board[j] - (i - j))
			return (0);
	}
	return (1);
}

void	dfs(int cnt, int *board, int *res)
{
	int	i;
	int	j;
	
	if (cnt == 10)
	{
		i = 0;
		while (i < 10)
			write(1,&board[i],1);
		write(1,"\n",1);
		res++;
		return ;
	}
	i = -1;
	j = -1;
	while (++i < 10)
	{
		if (board[i] == -1)
		{
			while(++j < 10)
			{
				board[cnt] = j;
				if (check(board, i))
				{
					dfs(cnt + 1, board, res);
					board[cnt] = -1;
				}
			}			
		}
	}
}

int ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int res;

	res = 0;
	i = 0;
	while(i < 10)
		board[i] = -1;
	dfs(0,board, &res);
	return (res);
}