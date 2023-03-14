/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:38:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/14 18:57:30 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	child_work(t_arg *arg)
{
	
}

void	parent_work(t_arg *arg)
{
	
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	init_arg(&arg, argc, argv, envp);
	if (argc < 5)
		exit_err(&arg, NULL, "Wrong Usage\n", 1);
	parse_to_arg(&arg);
	if (pipe(arg.pipe_fd1) < 0)
		exit_err(&arg, "pipe error", NULL, 1);
	if (pipe(arg.pipe_fd2) < 0)
		exit_err(&arg, "pipe error", NULL, 1);
	while (arg.cmd_cnt--)
	{
		arg.pid = fork();
		if (arg.pid < 0)
			exit_err(&arg, "fork error", NULL, 1);
		if (arg.pid == 0)
			child_work(&arg);
		else
			parent_work(&arg);
	}
}
