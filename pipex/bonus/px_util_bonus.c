/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_util_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:21:39 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/16 20:17:18 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

void	exit_err(t_arg *arg, char *str, int status)
{
	static int	i = -1;

	perror(str);
	free_arg(arg->path);
	free_arg(arg->cmd);
	if (arg->cmd_arg)
	{
		while (arg->cmd_arg[++i])
			free_arg(arg->cmd_arg[i]);
		free(arg->cmd_arg);
	}
	exit(status);
}

void	init_arg(t_arg *arg, int argc, char **argv, char **envp)
{
	arg->path = NULL;
	arg->cmd_arg = NULL;
	arg->cmd = NULL;
	arg->argv = argv;
	arg->envp = envp;
	arg->argc = argc;
	arg->here_doc = 0;
	arg->pipe_even[0] = 0;
	arg->pipe_even[1] = 0;
	arg->pipe_odd[0] = 0;
	arg->pipe_odd[1] = 0;
}
