/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:41:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/03 17:52:43 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_img(t_game *game, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(game->img->mlx, game->img->win, game->img->t, \
		game->p_xy[1] * 32, game->p_xy[0] * 32);
	mlx_put_image_to_window(game->img->mlx, game->img->win, game->img->p, \
	game->p_xy[1] * 32, game->p_xy[0] * 32);
}

static	int	key_move(int *cor, char c, t_game *game)
{
	mlx_put_image_to_window(game->img->mlx, game->img->win, game->img->t, \
	game->p_xy[1] * 32, game->p_xy[0] * 32);
	if (c == 's' || c == 'd')
		(*cor)++;
	else
		(*cor)--;
	if (game->map[game->p_xy[0]][game->p_xy[1]] == 'C')
	{
		game->map[game->p_xy[0]][game->p_xy[1]] = '0';
		set_img(game, 'C');
		game->c_cnt--;
	}
	else if (game->map[game->p_xy[0]][game->p_xy[1]] == '0')
		set_img(game, '0');
	else if (game->map[game->p_xy[0]][game->p_xy[1]] == 'E')
	{
		set_img(game, 'E');
		game->escape = 1;
	}
	return (1);
}

static int	is_moveable(t_game *game, int nx, int ny)
{
	nx += game->p_xy[0];
	ny += game->p_xy[1];
	if (nx < 0 || ny < 0 || nx >= game->map_height || ny >= game->map_width)
		return (0);
	if (game->map[nx][ny] == '1' || game->escape)
		return (0);
	if (game->map[nx][ny] == 'E' && game->c_cnt)
		return (0);
	return (1);
}

int	key_press(int keycode, t_game *game)
{
	static int	cnt = 0;

	if (keycode == KEY_W && is_moveable(game, -1, 0))
		cnt += key_move(&game->p_xy[0], 'w', game);
	else if (keycode == KEY_S && is_moveable(game, 1, 0))
		cnt += key_move(&game->p_xy[0], 's', game);
	else if (keycode == KEY_A && is_moveable(game, 0, -1))
		cnt += key_move(&game->p_xy[1], 'a', game);
	else if (keycode == KEY_D && is_moveable(game, 0, 1))
		cnt += key_move(&game->p_xy[1], 'd', game);
	else if (keycode == KEY_ESC || game->escape)
		normal_exit(game);
	printf("moved : %d\n", cnt);
	return (0);
}
