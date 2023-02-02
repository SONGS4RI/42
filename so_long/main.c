/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/02 15:42:43 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leaks()/////////
{
	system("leaks so_long");
}

int	key_press(int keycode, t_game *game)
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
	printf("x: %d, y: %d\n",game->p_xy[0], game->p_xy[1]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	void	*mlx;
	void	*win;
	t_img	img;

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
	mlx = mlx_init();
	win = mlx_new_window(mlx, game->map_width * 32, game->map_height * 32, "mlx_test");
	img.p = mlx_xpm_file_to_image(mlx, "./textures/player.xpm", &img.img_w, &img.img_h);
	img.e = mlx_xpm_file_to_image(mlx, "./textures/exit.xpm", &img.img_w, &img.img_h);
	img.c = mlx_xpm_file_to_image(mlx, "./textures/chest.xpm", &img.img_w, &img.img_h);
	img.t = mlx_xpm_file_to_image(mlx, "./textures/tile.xpm", &img.img_w, &img.img_h);
	img.w = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &img.img_w, &img.img_h);
	mlx_put_image_to_window(mlx, win, img.p, 0, 0);
	mlx_put_image_to_window(mlx, win, img.e, 32, 0);
	mlx_put_image_to_window(mlx, win, img.c, 64, 0);
	mlx_put_image_to_window(mlx, win, img.t, 0, 32);
	mlx_put_image_to_window(mlx, win, img.w, 32, 32);
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, game);
	mlx_loop(mlx);
	// free_map(game->map);
	// free_map(game->vis);
	// close(game->fd);
	// free(game);
	return (0);
}
