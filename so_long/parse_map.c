/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:50 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/03 14:36:17 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strjoin_free(char **s1, char **s2)
{
	char	*res;

	res = ft_strjoin(*s1, *s2);
	if (s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (res);
}

static int	check_double_nl(char *res)
{
	int	idx;
	int	flag;

	flag = 0;
	idx = -1;
	while (res[++idx])
	{
		if (res[idx] == '\n')
		{
			if (flag)
				return (1);
			flag = 1;
		}
		else
			flag = 0;
	}
	return (0);
}

static void	game_init(t_game *game)
{
	game->map = NULL;
	game->vis = NULL;
	game->img = NULL;
	game->c_cnt = 0;
}

void	parse_map(t_game *game)
{
	int		read_byte;
	char	*res;
	char	*tmp;

	res = NULL;
	game_init(game);
	while (1)
	{
		tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_byte = read(game->fd, tmp, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(tmp);
			err_free(&game, &res, "Read Error");
		}
		tmp[read_byte] = '\0';
		res = ft_strjoin_free(&res, &tmp);
		if (read_byte < BUFFER_SIZE)
			break ;
	}
	if (check_double_nl(res))
		err_free(&game, &res, "Invalid Map : nl");
	game->map = ft_split(res, '\n');
	check_map(res, game);
}
