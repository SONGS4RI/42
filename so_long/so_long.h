/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:08:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/01 18:12:42 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_param{
	int		x;
	int		y;
}t_param;

typedef struct s_game
{
	char	**map;
	char	**vis;
	int		fd;
	int		map_height;
	int		map_width;
	int		p_xy[2];
}t_game;

void		leaks();

void		free_map(char **map);
void		err_free(t_game **game, char **str, char *err_str);

static char	*ft_strjoin_free(char **s1, char **s2);
static int	check_double_nl(char *res);
void		parse_map(t_game *game);

static void	is_mapsquare(t_game *game);
static void	is_wallaround(t_game *game);
static int	invalid_alpha(char c);
static void	check_cep(t_game *game, int e_cnt, int c_cnt, int p_cnt);
void		check_map(char *res, t_game *game);

static int	ewsn(int idx);
static void	dfs_vis(int x, int y, t_game *game);
static void	check_vis(t_game *game);
void		can_escape(t_game *game);


#endif