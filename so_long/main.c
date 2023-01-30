/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/30 16:13:01 by jahlee           ###   ########.fr       */
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
		print_err_free(NULL);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		print_err_free(NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_err_free(&game);
	parse_map(fd, game);
	for(int i=0;game->map[i];i++) printf("%s\n",game->map[i]);///////////////
	free(game->map);
	close(fd);
	return (0);
}
