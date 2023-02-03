/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/03 21:12:04 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_ber(char *s1, char *ber)
{
	int		idx_s;
	int		idx;

	idx_s = 0;
	idx = 4;
	while (s1[idx_s])
		idx_s++;
	while (--idx >= 0)
	{
		printf("%c, %c\n",s1[idx_s-1] ,ber[idx]);
		if (s1[--idx_s] != ber[idx])
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_img	img;

	if (argc != 2)
		err_free(NULL, NULL, "Wrong Usage");
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		err_free(NULL, NULL, "Malloc Error");
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0 || !is_ber(argv[1], ".ber"))
		err_free(&game, NULL, "Wrong File");
	parse_map(game);
	game->img = &img;
	map_to_window(game->img, game);
	return (0);
}
