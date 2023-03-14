/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:38:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/14 15:57:49 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_work(t_arg *arg)
{
	arg->infile = open(arg->argv[1], O_RDONLY);
	if (arg->infile == -1)
		exit_err(arg, arg->argv[1], NULL, 1);
	if (arg->cmd1 == NULL)
		exit_err(arg, arg->cmd_arg1[0], "command not found", 127);
	close(arg->pipe_fd[0]);
	if (dup2(arg->infile, STDIN_FILENO) == -1)
		exit_err(arg, "child dup2 error", NULL, 1);
	if (dup2(arg->pipe_fd[1], STDOUT_FILENO) == -1)
		exit_err(arg, "child dup2 error", NULL, 1);
	close(arg->pipe_fd[1]);
	close(arg->infile);
	if (execve(arg->cmd1, arg->cmd_arg1, arg->envp) == -1)
		exit_err(arg, "child execve error", NULL, 1);
}

void	parent_work(t_arg *arg)
{
	waitpid(arg->pid, NULL, WNOHANG);
	arg->outfile = open(arg->argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->outfile == -1)
		exit_err(arg, arg->argv[4], NULL, 1);
	if (arg->cmd2 == NULL)
		exit_err(arg, arg->cmd_arg2[0], "command not found", 127);
	close(arg->pipe_fd[1]);
	if (dup2(arg->pipe_fd[0], STDIN_FILENO) == -1)
		exit_err(arg, "parent dup2 error", NULL, 1);
	if (dup2(arg->outfile, STDOUT_FILENO) == -1)
		exit_err(arg, "parent dup2 error", NULL, 1);
	close(arg->pipe_fd[0]);
	close(arg->outfile);
	if (execve(arg->cmd2, arg->cmd_arg2, arg->envp) == -1)
		exit_err(arg, "parent execve error\n", NULL, 1);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	init_arg(&arg);
	arg.argv = argv;
	arg.envp = envp;
	if (argc != 5)
		exit_err(&arg, NULL, "Wrong Usage\n", 1);
	parse_to_arg(&arg);
	if (pipe(arg.pipe_fd) < 0)
		exit_err(&arg, "pipe error", NULL, 1);
	arg.pid = fork();
	if (arg.pid < 0)
		exit_err(&arg, "fork error", NULL, 1);
	if (arg.pid == 0)
		child_work(&arg);
	else
		parent_work(&arg);
}
