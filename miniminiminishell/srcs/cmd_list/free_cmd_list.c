#include "../../includes/miniminiminishell.h"

static void	free_redirection_list(t_redirection *redirection_list)
{
	t_redirection	*tmp;

	while (redirection_list)
	{
		free(redirection_list->type);
		free(redirection_list->file);
		tmp = redirection_list;
		redirection_list = redirection_list->next;
		free(tmp);
	}
}

void	free_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*tmp;

	while (cmd_list)
	{
		free_2d_arr(cmd_list->argv);
		free_redirection_list(cmd_list->redirection);
		tmp = cmd_list;
		cmd_list = cmd_list->next;
		free(tmp);
	}
}
