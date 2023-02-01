/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/01 19:58:11 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leaks()/////////
{
	system("leaks so_long");
}

void	param_init(t_param *param, t_game *game)
{
	param->x = game->p_xy[0];
	param->y = game->p_xy[1];
}

int	key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", param->x, param->y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_param	param;
	void	*mlx;
	void	*win;
	void	*player;
	void	*exit;
	void	*chest;
	void	*tile;
	void	*wall;
	int img_width;
	int img_height;

	atexit(leaks);///////////
	if (argc != 2)
		err_free(NULL, NULL, "Wrong Usage");
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		err_free(NULL, NULL, "Malloc Error");
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		err_free(&game, NULL, "Wrong File");
	parse_map(game);
	param_init(&param, game);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 700, "mlx_test");
	player = mlx_xpm_file_to_image(mlx, "./textures/player.xpm", &img_width, &img_height);
	exit = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm", &img_width, &img_height);
	chest = mlx_xpm_file_to_image(mlx, "./textures/chest.xpm", &img_width, &img_height);
	tile = mlx_xpm_file_to_image(mlx, "./textures/tile.xpm", &img_width, &img_height);
	wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, player, 0, 0);
	mlx_put_image_to_window(mlx, win, exit, 64, 0);
	mlx_put_image_to_window(mlx, win, chest, 128, 0);
	mlx_put_image_to_window(mlx, win, tile, 0, 64);
	mlx_put_image_to_window(mlx, win, wall, 64, 64);
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(mlx);
	free_map(game->map);
	free_map(game->vis);
	close(game->fd);
	free(game);
	return (0);
}
