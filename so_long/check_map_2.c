/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:00:26 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/01 16:06:41 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ewsn(int idx)
{
	if (idx % 4 == 3)
		return (0);
	return (idx % 4 - 1);
}

void	dfs_vis(int x, int y, t_game *game)
{
	int	nx;
	int	ny;
	int	dir;

	dir = -1;
	while (++dir < 4)
	{
		nx = x + ewsn(dir);
		ny = y + ewsn(dir + 1);
		if (nx < 0 || ny < 0 || nx >= game->map_height || ny >= game->map_width)
			continue ;
		if (game->map[nx][ny] == '1' || game->map[nx][ny] == 'E' )
			continue ;
		if (game->vis[nx][ny] == '1')
			continue ;
		game->vis[nx][ny] = '1';
		dfs_vis(nx, ny, game);
	}
}

void	check_vis(t_game *game)
{
	int	x;
	int	y;
	int	idx;

	x = -1;
	while (++x < game->map_height)
	{
		y = -1;
		while (++y < game->map_width)
		{
			if (game->map[x][y] == 'C' && game->vis[x][y] != '1')
				print_err_free(&game, NULL);
			else if (game->map[x][y] == 'E')
			{
				idx = -1;
				while (++idx < 4)
				{
					if (game->vis[x + ewsn(idx)][y + ewsn(idx + 1)] == '1')
						break ;
				}
				if (idx == 4)
					print_err_free(&game, NULL);
			}
		}
	}
}

void	can_escape(t_game *game)
{
	int		idx;
	int		i;

	idx = -1;
	game->vis = (char **)ft_calloc(sizeof(char *), game->map_height + 1);
	while (++idx < game->map_height)
		game->vis[idx] = (char *)ft_calloc(sizeof(char), game->map_width + 1);
	while (--idx >= 0)
	{
		i = -1;
		while (++i < game->map_width)
			game->vis[idx][i] = '0';
	}
	game->vis[game->p_xy[0]][game->p_xy[1]] = '1';
	dfs_vis(game->p_xy[0], game->p_xy[1], game);
	check_vis(game);
}
