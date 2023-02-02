/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/02 15:59:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leaks()/////////
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	*game;
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
	map_to_window(&img, game);
	// free_map(game->map);
	// free_map(game->vis);
	// close(game->fd);
	// free(game);
	return (0);
}
