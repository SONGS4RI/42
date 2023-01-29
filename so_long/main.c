/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/29 17:44:59 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(void)
{
	printf("Error\n");
	exit(1);
}

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

char	*ft_strjoin_free(char **s1, char **s2)
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

void	parse_map(int fd, t_game *game)
{
	int		read_byte;
	char	*res;
	char	*tmp;

	res = NULL;
	while (1)
	{
		tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_byte = read(fd, tmp, BUFFER_SIZE);
		if (read_byte == -1)//read err 났을때
		{
			print_err();
			break;
		}
		tmp[read_byte] = '\0';
		res = ft_strjoin_free(&res, &tmp);
		if (read_byte < BUFFER_SIZE)
			break ;
	}
	game->map = ft_split(res, '\n');
	if (res)
		free(res);
}

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
		print_err();
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		print_err();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_err();
	parse_map(fd, game);
	for(int i=0;game->map[i];i++) printf("%s\n",game->map[i]);///////////
	close(fd);
	return (0);
}
