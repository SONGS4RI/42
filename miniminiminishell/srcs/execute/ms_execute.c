#include "../../includes/miniminiminishell.h"

char	*get_cmd_file(char *cmd, char **path_list)
{
	char	*cmd_file;
	char	*temp;

	if (cmd == NULL)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	temp = ft_strjoin("/", cmd);
	while (path_list && *path_list)
	{
		cmd_file = ft_strjoin(*path_list, temp);
		if (access(cmd_file, X_OK) == 0)
		{
			free(temp);
			return (cmd_file);
		}
		free(cmd_file);
		path_list++;
	}
	free(temp);
	return (NULL);
}

int	execute_builtin(t_info *info, t_cmd *cmd_list, int cnt)
{
	if (set_redirection_fd(cmd_list, cnt) == -1)
	{
		g_exit_status = 1;
		return (0);
	}
	dup2(info->stdin, STDIN_FILENO);
	if (ft_strncmp(cmd_list->argv[0], "cd", 2) == 0)
		g_exit_status = ms_cd(info, cmd_list->argv);
	if (ft_strncmp(cmd_list->argv[0], "echo", 4) == 0)
		g_exit_status = ms_echo(cmd_list->argv);
	if (ft_strncmp(cmd_list->argv[0], "env", 3) == 0)
		g_exit_status = ms_env(info->env_list);
	if (ft_strncmp(cmd_list->argv[0], "exit", 4) == 0)
		g_exit_status = ms_exit(info, cmd_list);
	if (ft_strncmp(cmd_list->argv[0], "export", 6) == 0)
		g_exit_status = ms_export(info, cmd_list->argv);
	if (ft_strncmp(cmd_list->argv[0], "pwd", 3) == 0)
		g_exit_status = ms_pwd();
	if (ft_strncmp(cmd_list->argv[0], "unset", 5) == 0)
		g_exit_status = ms_unset(info, cmd_list->argv);
	dup2(info->stdout, STDOUT_FILENO); ///////// 메인으로 옮겨야 할수동 ...ㅇㅋㅇㅋ췍췍
	return (1);
}

int	check_builtin(t_info *info, t_cmd *cmd_list, int cnt)
{
	char	*cmd;

	if (cmd_list->argv == NULL)
		return (0);
	cmd = cmd_list->argv[0];
	if ((ft_strlen(cmd) == 2 && ft_strncmp(cmd, "cd", 2) == 0) \
		|| (ft_strlen(cmd) == 4 && ft_strncmp(cmd, "echo", 4) == 0) \
		|| (ft_strlen(cmd) == 3 && ft_strncmp(cmd, "env", 3) == 0) \
		|| (ft_strlen(cmd) == 4 && ft_strncmp(cmd, "exit", 4) == 0) \
		|| (ft_strlen(cmd) == 6 && ft_strncmp(cmd, "export", 6) == 0) \
		|| (ft_strlen(cmd) == 3 && ft_strncmp(cmd, "pwd", 3) == 0) \
		|| (ft_strlen(cmd) == 5 && ft_strncmp(cmd, "unset", 5) == 0))
		return (execute_builtin(info, cmd_list, cnt));
	return (0);
}

void	execute_multiple_cmd(t_info *info, t_cmd *cmd_list)
{
	char	*file;
	int		cnt;
	pid_t	pid;

	cnt = 0;
	while (cmd_list)
	{
		if (cmd_list->next && pipe(cmd_list->pipe) == -1)
		{
			// err 출력
			return ;
		}
		if (cmd_list->prev)
			close(cmd_list->prev->pipe[1]); // 안써서 닫아
		pid = fork();
		if (pid < 0)
			ms_error("fork", NULL);
		else if (pid == 0)
		{
			signal(SIGINT, quit_handler);
			signal(SIGQUIT, quit_handler);
			if (cmd_list->prev && dup2(cmd_list->prev->pipe[0], STDIN_FILENO) == -1)
			{
				//err 출력
				g_exit_status = 1;
				return ;
			}
			if (cmd_list->next)
			{
				close(cmd_list->pipe[0]);
				if (dup2(cmd_list->pipe[1], STDOUT_FILENO) == -1)
				{
					//err 출력
					g_exit_status = 1;
					return ;
				}
			}
			if (check_builtin(info, cmd_list, cnt))
				exit(g_exit_status);
			else
			{
				if (set_redirection_fd(cmd_list, cnt) == -1)
				{
					g_exit_status = 1;
					return ;
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
		}
		if (cmd_list->prev)
			close(cmd_list->prev->pipe[0]);
		cmd_list = cmd_list->next;
		cnt++;
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &g_exit_status, 0);
	while (--cnt)
		wait(0); // 자식이 있을 때만 !!!
	// signal(SIGINT, parent_handler);
	if (WIFSIGNALED(g_exit_status)) // signal에 의하여 terminate 되었는지를 확인
		g_exit_status = 128 + WTERMSIG(g_exit_status); // WIFSIGNALED의 값이 참인 경우 어느 signal에 의하여 terminate 되었는지를 알아냄
	if (WIFEXITED(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status); // exit code 알아냄
}

void	ms_execute(t_info *info, t_cmd *cmd_list)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ms_error("fork", NULL);
		g_exit_status = 1;
		return ;
	}
	else if (pid == 0)
		execute_heredoc(info, cmd_list);
	signal(SIGINT, SIG_IGN);
	wait(&g_exit_status);
	// signal(SIGINT, parent_handler);
	if (WIFEXITED(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status); // exit code 알아냄
	if (WIFSIGNALED(g_exit_status)) // signal에 의하여 terminate 되었는지를 확인
		g_exit_status = 1; // WIFSIGNALED의 값이 참인 경우 어느 signal에 의하여 terminate 되었는지를 알아냄
	else
	{
		if (cmd_list->next)
			execute_multiple_cmd(info, cmd_list);
		else
			execute_single_cmd(info, cmd_list);
	}
	unlink_heredoc_tmp(cmd_list);
} 
