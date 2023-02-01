/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:12:09 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/01 16:32:31 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	if (map)
	{
		while (map[++i])
			free(map[i]);
		free(map);
	}
}

void	err_free(t_game **game, char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	if (*game)
	{
		if ((*game)->map)
			free_map((*game)->map);
		if ((*game)->vis)
			free_map((*game)->vis);
		if ((*game)->fd >= 0)
			close((*game)->fd);
		free(*game);
		(*game)->map = NULL;
		(*game)->vis = NULL;
		(*game) = NULL;
	}
	printf("Error\n");
	exit(1);
}
