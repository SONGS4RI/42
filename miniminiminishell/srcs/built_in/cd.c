#include "../../includes/miniminiminishell.h"

int	ms_cd(char *path)
{
	if (access(path, F_OK) == 0 && chdir(path) == 0)
		return (0);
	printf("minishell: cd: %s: No such file or directory\n", path);
	return (-1);
}
