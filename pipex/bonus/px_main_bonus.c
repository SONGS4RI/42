/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:38:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/14 19:57:27 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	child_work(t_arg *arg, int i)
{

	if (i % 2 == 0)
	{
		if (arg->here_doc == 1 && i == 0)
		{
			if (dup2(arg->infile, STDIN_FILENO) == -1)
				exit_err(arg, "dup error", NULL, 1);
			arg->here_doc = 2;
		}
		else if (dup2(arg->pipe_fd2[0], STDIN_FILENO) == -1)
			exit_err(arg, "dup error", NULL, 1);
		if (dup2(arg->pipe_fd1[1], STDOUT_FILENO) == -1)
			exit_err(arg, "dup error", NULL, 1);
	}
	else
	{
		if (dup2(arg->pipe_fd1[0], STDIN_FILENO) == -1)
			exit_err(arg, "dup error", NULL, 1);
		if (dup2(arg->pipe_fd2[1], STDOUT_FILENO) == -1)
			exit_err(arg, "dup error", NULL, 1);
	}
}

void	parent_work(t_arg *arg)
{
	
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	int		i;

	i = -1;
	init_arg(&arg, argc, argv, envp);
	if (argc < 5)
		exit_err(&arg, NULL, "Wrong Usage\n", 1);
	parse_to_arg(&arg);
	if (pipe(arg.pipe_fd1) < 0)
		exit_err(&arg, "pipe error", NULL, 1);
	if (pipe(arg.pipe_fd2) < 0)
		exit_err(&arg, "pipe error", NULL, 1);
	while (++i < arg.cmd_cnt * 2)
	{
		arg.pid = fork();
		if (arg.pid < 0)
			exit_err(&arg, "fork error", NULL, 1);
		if (arg.pid == 0)
			child_work(&arg, i);
	}
	parent_work(&arg);
}
