#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	ft_memset(&cub, 0, sizeof(t_cub));
	if (argc != 2)
		cub_error(&cub, "Invalid number of arguments");
	init_map(&cub, argv[1]);
	start_game(&cub);
	return (0);
}
