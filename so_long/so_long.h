/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:08:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/31 17:15:49 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_game
{
	char	**map;
	int		map_height;
	int		map_width;
	int		E_xy[2];
	int		P_xy[2];
}t_game;

void		 leaks();
static char	*ft_strjoin_free(char **s1, char **s2);
void		parse_map(int fd, t_game *game);
void		free_map(char **map);
void		print_err_free(t_game **game, char **str);
void		is_wallaround(t_game *game);
void		is_mapsquare(t_game *game);
void 		save_ep(t_game *game, char c, int x, int y);
int			invalid_alpha(char c);
void		check_cep(t_game *game, int e_cnt, int c_cnt, int p_cnt);
void		check_map(char *res, t_game *game);

#endif