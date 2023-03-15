/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_util_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:21:39 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/15 17:54:37 by jahlee           ###   ########.fr       */
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

void	exit_err(t_arg *arg, char *str, char *err_msg, int status)
{
	static int	i = -1;

	ft_printf("%s: ", arg->argv[0] + 2);
	if (status == 127)
		ft_printf("%s: %s\n", str, err_msg);
	else
		perror(str);
	free_arg(arg->path);
	free_arg(arg->cmd);
	while (arg->cmd_arg[++i])
		free_arg(arg->cmd_arg[i]);
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
}
