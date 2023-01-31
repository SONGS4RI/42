/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:12:09 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/31 17:13:14 by jahlee           ###   ########.fr       */
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

void	print_err_free(t_game **game, char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	if (*game)
	{
		free_map((*game)->map);
		free(*game);
		(*game)->map = NULL;
		(*game) = NULL;
	}
	printf("Error\n");
	exit(1);
}