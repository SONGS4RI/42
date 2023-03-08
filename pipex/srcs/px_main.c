/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:38:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/08 18:06:39 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_arg(char **s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
}

void	exit_err(t_arg *arg, char *str)
{
	write(2, str, ft_strlen(str));
	free_arg(arg->path);
	free_arg(arg->cmd_arg1);
	free_arg(arg->cmd_arg2);
	if (arg->cmd1)
		free(arg->cmd1);
	if (arg->cmd2)
		free(arg->cmd2);
	exit(1);
}

void	init_arg(t_arg *arg)
{
	arg->path = NULL;
	arg->cmd_arg1 = NULL;
	arg->cmd_arg2 = NULL;
	arg->cmd1 = NULL;
	arg->cmd2 = NULL;
}

void	pipex(t_arg *arg)
{
	if (pipe(arg->pipe_fd) < 0)
		exit_err(arg, "pipe error\n");
	arg->pid = fork();
	if (arg->pid < 0)
		exit_err(arg, "fork error\n");
	if (arg->pid == 0)
	{
		close(arg->pipe_fd[0]);
		dup2(arg->infile, STDIN_FILENO);
		dup2(arg->pipe_fd[1], STDOUT_FILENO);
		close(arg->pipe_fd[1]);
		close(arg->infile);
		execve(arg->cmd1, arg->cmd_arg1, arg->envp);
	}
	else
	{

		close(arg->pipe_fd[1]);
		dup2(arg->pipe_fd[0], STDIN_FILENO);
		dup2(arg->outfile, STDOUT_FILENO);
		close(arg->pipe_fd[0]);
		close(arg->outfile);
		waitpid(arg->pid, NULL, WNOHANG);
		execve(arg->cmd2, arg->cmd_arg2, arg->envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	init_arg(&arg);
	arg.envp = envp;
	if (argc != 5)
		exit_err(&arg, "Wrong Usage: ./pipex file1 cmd1 cmd2 file2\n");
	arg.infile = open(argv[1], O_RDONLY);
	arg.outfile = open(argv[4], O_WRONLY);
	if (arg.infile == -1 || arg.outfile == -1)
		exit_err(&arg, "file open error\n");
	parse_to_arg(&arg, argv, envp);
	pipex(&arg);
	return (0);
}
