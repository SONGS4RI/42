/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:42:13 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/02 17:21:52 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_mapsquare(t_game *game)
{
	int	idx;

	idx = 0;
	game->map_width = ft_strlen(game->map[0]);
	while (game->map[++idx])
	{
		if (ft_strlen(game->map[idx]) != game->map_width)
			err_free(&game, 0, "Invalid Map : Not a Square");
	}
	game->map_height = idx;
}

static void	is_wallaround(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_width)
	{
		if (game->map[0][i] != '1')
			err_free(&game, 0, "Invalid Map : No Wall Around");
		if (game->map[game->map_height - 1][i] != '1')
			err_free(&game, 0, "Invalid Map : No Wall Around");
	}
	i = -1;
	while (++i < game->map_height)
	{
		if (game->map[i][0] != '1')
			err_free(&game, 0, "Invalid Map : No Wall Around");
		if (game->map[i][game->map_width - 1] != '1')
			err_free(&game, 0, "Invalid Map : No Wall Around");
	}
}

static int	invalid_alpha(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (0);
	return (1);
}

static void	check_cep(t_game *game, int e_cnt, int p_cnt)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->map_height)
	{
		y = -1;
		while (++y < game->map_width)
		{
			if (invalid_alpha(game->map[x][y]))
				err_free(&game, 0, "Invalid Map : Invalid Alphabet");
			if (game->map[x][y] == 'P')
			{
				game->p_xy[0] = x;
				game->p_xy[1] = y;
				p_cnt++;
			}
			else if (game->map[x][y] == 'C')
				game->c_cnt++;
			else if (game->map[x][y] == 'E')
				e_cnt++;
		}
	}
	if (e_cnt != 1 || p_cnt != 1 || game->c_cnt == 0)
		err_free(&game, 0, "Invalid Map : Objects Not Satisfied");
}

void	check_map(char *res, t_game *game)
{
	if (res[0] == '\0')
		err_free(&game, &res, "Invalid Map : Empty Map");
	if (res)
		free(res);
	is_mapsquare(game);
	is_wallaround(game);
	check_cep(game, 0, 0);
	can_escape(game);
}
