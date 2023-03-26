#include "../includes/miniminiminishell.h"

void	ms_error(char *message)
{
	perror(message);
	exit(1);
}

void	free_2d_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
