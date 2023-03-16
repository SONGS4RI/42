/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:38:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/16 20:45:58 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	execute_cmd(t_arg *arg, int idx)
{
	if (!arg->cmd)
		exit_err(arg, "init err", 1);
	if (!arg->cmd[idx])
		exit_err(arg, "command not found", 127);
	execve(arg->cmd[idx], arg->cmd_arg[idx], arg->envp);
	exit_err(arg, "execve error", 1);
}

void	child_work(t_arg *arg, int idx)
{
	if (idx % 2 == 0)
	{
		close(arg->pipe_even[0]);
		if (dup2(arg->pipe_even[1], STDOUT_FILENO) == -1)
			exit_err(arg, "dup2 error", 1);
		close(arg->pipe_even[1]);
	}
	else
	{
		close(arg->pipe_odd[0]);
		if (dup2(arg->pipe_odd[1], STDOUT_FILENO) == -1)
			exit_err(arg, "dup2 error", 1);
		close(arg->pipe_odd[1]);
	}
	execute_cmd(arg, idx);
}

void	parent_work(t_arg *arg, int idx)
{
	waitpid(arg->pid, NULL, 0);
	if (idx % 2 == 0)
	{
		close(arg->pipe_even[1]);
		if (dup2(arg->pipe_even[0], STDIN_FILENO) == -1)
			exit_err(arg, "dup2 error", 1);
		close(arg->pipe_even[0]);
	}
	else
	{
		close(arg->pipe_odd[1]);
		if (dup2(arg->pipe_odd[0], STDIN_FILENO) == -1)
			exit_err(arg, "dup2 error", 1);
		close(arg->pipe_odd[0]);
	}
}

void	pipe_work(t_arg *arg, int idx)
{
	if (idx % 2 == 0)
	{
		if (pipe(arg->pipe_even) < 0)
			exit_err(arg, "pipe error", 1);
	}
	else
	{
		if (pipe(arg->pipe_odd) < 0)
			exit_err(arg, "pipe error", 1);
	}
	arg->pid = fork();
	if (arg->pid < 0)
		exit_err(arg, "fork error", 1);
	if (arg->pid == 0)
		child_work(arg, idx);
	else
		parent_work(arg, idx);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	int		idx;

	idx = -1;
	init_arg(&arg, argc, argv, envp);
	if (argc < 5)
		exit_err(&arg, "Wrong Usage", 1);
	parse_to_arg(&arg);
	set_infile_fd(&arg);
	while (++idx < arg.cmd_cnt - 1)
		pipe_work(&arg, idx);
	set_outfile_fd(&arg);
	execute_cmd(&arg, idx);
	return (0);
}
