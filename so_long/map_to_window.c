/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:51:56 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/02 16:15:52 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_press(int keycode, t_game *game)
{
	static int	cnt = 0;

	if (keycode == KEY_W && game->p_xy[0] < game->map_height - 1)
		game->p_xy[0]++;
	else if (keycode == KEY_S && game->p_xy[0] > 0)
		game->p_xy[0]--;
	else if (keycode == KEY_A && game->p_xy[1] > 0)
		game->p_xy[1]--;
	else if (keycode == KEY_D && game->p_xy[1] < game->map_width - 1)
		game->p_xy[1]++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", game->p_xy[0], game->p_xy[1]);
	return (0);
}

static void	set_img(t_img *img, t_game *game)
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
			mlx_put_image_to_window(img->mlx, img->win, img->t, y * 32, x * 32);
			if (game->map[x][y] == 'C')
				mlx_put_image_to_window(img->mlx, img->win, img->c, \
				y * 32, x * 32);
			else if (game->map[x][y] == 'E')
				mlx_put_image_to_window(img->mlx, img->win, img->e, \
				y * 32, x * 32);
			else if (game->map[x][y] == 'P')
				mlx_put_image_to_window(img->mlx, img->win, img->p, \
				y * 32, x * 32);
			else if (game->map[x][y] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->w, \
				y * 32, x * 32);
		}
	}
}

void	map_to_window(t_img *img, t_game *game)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, game->map_width * 32, \
	game->map_height * 32, "mlx_test");
	img->p = mlx_xpm_file_to_image(img->mlx, "./textures/player.xpm", \
	&img->img_w, &img->img_h);
	img->e = mlx_xpm_file_to_image(img->mlx, "./textures/exit.xpm", \
	&img->img_w, &img->img_h);
	img->c = mlx_xpm_file_to_image(img->mlx, "./textures/chest.xpm", \
	&img->img_w, &img->img_h);
	img->t = mlx_xpm_file_to_image(img->mlx, "./textures/tile.xpm", \
	&img->img_w, &img->img_h);
	img->w = mlx_xpm_file_to_image(img->mlx, "./textures/wall.xpm", \
	&img->img_w, &img->img_h);
	set_img(img, game);
	mlx_hook(img->win, X_EVENT_KEY_RELEASE, 0, &key_press, game);
	mlx_loop(img->mlx);
}
