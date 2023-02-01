/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/01 15:40:34 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void leaks()/////////
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	atexit(leaks);///////////
	if (argc != 2)
		print_err_free(NULL, NULL);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		print_err_free(NULL, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_err_free(&game, NULL);
	parse_map(fd, game);
	for(int i=0;game->map[i];i++) printf("%s\n",game->map[i]);///////////////
	free_map(game->map);
	free_map(game->vis);
	free(game);
	close(fd);
	return (0);
}
