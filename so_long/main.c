/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/02 17:21:11 by jahlee           ###   ########.fr       */
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
	game->img = &img;
	map_to_window(game->img, game);
	return (0);
}
