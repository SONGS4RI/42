/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:21:39 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/09 18:24:00 by jahlee           ###   ########.fr       */
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

void	exit_err(t_arg *arg, char *str, int status)
{
	write(2, str, ft_strlen(str));
	free_arg(arg->path);
	free_arg(arg->cmd_arg1);
	free_arg(arg->cmd_arg2);
	if (arg->cmd1)
		free(arg->cmd1);
	if (arg->cmd2)
		free(arg->cmd2);
	exit(status);
}

void	init_arg(t_arg *arg)
{
	arg->path = NULL;
	arg->cmd_arg1 = NULL;
	arg->cmd_arg2 = NULL;
	arg->cmd1 = NULL;
	arg->cmd2 = NULL;
}
