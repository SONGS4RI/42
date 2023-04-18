#include "../../includes/miniminiminishell.h"

static void	execute_single_cmd_parent(void)
{
	if (WIFSIGNALED(g_exit_status)) // signal에 의하여 terminate 되었는지를 확인
		g_exit_status = 128 + WTERMSIG(g_exit_status); // WIFSIGNALED의 값이 참인 경우 어느 signal에 의하여 terminate 되었는지를 알아냄
	if (WIFEXITED(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status); // exit code 알아냄
}

static void	execute_single_cmd_child(t_info *info, t_cmd *cmd_list)
{
	char	*file;

	if (set_redirection_fd(cmd_list, 0) == -1)
	{
		g_exit_status = 1;
		exit(g_exit_status);
	}
	if (cmd_list->argv == NULL)
		exit(g_exit_status);
	file = get_cmd_file(cmd_list->argv[0], info->path_list);
	if (file == NULL)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd_list->argv[0], STDERR_FILENO);
		if (info->path_list)
			ft_putendl_fd(": command not found", STDERR_FILENO);
		else
			ft_putendl_fd(": No such file or directory", STDERR_FILENO);
		g_exit_status = 127;
		exit(g_exit_status);
	}
	execve(file, cmd_list->argv, env_list_to_envp(info->env_list));
	ms_error("execve", NULL);
	g_exit_status = 1;
	exit(g_exit_status);
}

void	execute_single_cmd(t_info *info, t_cmd *cmd_list)
{
	pid_t	pid;

	if (!check_builtin(info, cmd_list, 0))
	{
		pid = fork();
		if (pid < 0)
			ms_error("fork", NULL);
		else if (pid == 0)
		{
			signal(SIGINT, quit_handler);
			signal(SIGQUIT, quit_handler);
			execute_single_cmd_child(info, cmd_list);
		}
		else
		{
			signal(SIGINT, SIG_IGN);
			wait(&(g_exit_status));
			// signal(SIGINT, parent_handler);
			execute_single_cmd_parent();
		}
	}
}
