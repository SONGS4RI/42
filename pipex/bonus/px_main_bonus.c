/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:38:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/15 20:12:44 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	execute_cmd(t_arg *arg, int idx)
{
	if (!arg->cmd[idx])
		exit_err(arg, arg->cmd_arg[idx][0], "command not found", 127);
	execve(arg->cmd[idx], arg->cmd_arg[idx], arg->envp);
	exit_err(arg, "execve error", NULL, 1);
}

void	child_work(t_arg *arg, int i)
{
	if (i % 2 == 0)
	{
		if (i == 0)
		{
			if (arg->here_doc)
			{
				if (dup2(arg->infile, STDIN_FILENO) == -1)
					exit_err(arg, "dup error", NULL, 1);
			}
			else
			{
				arg->infile = open(arg->argv[1], O_RDONLY);
				if (arg->infile == -1)
					exit_err(arg, arg->argv[1], NULL, 1);
			}
		}
		else if (dup2(arg->pipe_odd[0], STDIN_FILENO) == -1)
			exit_err(arg, "dup error", NULL, 1);
		if (dup2(arg->pipe_even[1], STDOUT_FILENO) == -1)
			exit_err(arg, "dup error", NULL, 1);
	}
	else
	{
		if (arg->here_doc && i == arg->cmd_cnt * 2 - 1)
		{
			arg->outfile = open(arg->argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (arg->outfile == -1)
				exit_err(arg, arg->argv[4], NULL, 1);
			if (dup2(arg->outfile, STDOUT_FILENO) == -1)
				exit_err(arg, "dup error", NULL, 1);
		}
		if (dup2(arg->pipe_even[0], STDIN_FILENO) == -1)
			exit_err(arg, "dup error", NULL, 1);
		if (dup2(arg->pipe_odd[1], STDOUT_FILENO) == -1)
			exit_err(arg, "dup error", NULL, 1);
	}
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
	set_infile_fd(&arg);
	while (++i < arg.cmd_cnt)
	{
	}
	set_outfile_fd(&arg);
	execute_cmd(&arg, argc - 2);
	return (0);
}
