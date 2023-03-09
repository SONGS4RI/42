/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:02:41 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/09 20:15:31 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path_envp(char **envp)
{
	char	*path;

	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	path = *envp + 5;
	return (ft_split(path, ':'));
}

char	*get_cmd_argv(char **path, char *cmd)
{
	char			*tmp_path;
	char			*tmp_cmd;
	int				idx;

	idx = -1;
	if (access(cmd, X_OK) != -1)
		return (cmd);
	tmp_cmd = ft_strjoin("/", cmd);
	while (path[++idx])
	{
		tmp_path = ft_strjoin(path[idx], tmp_cmd);
		if (access(tmp_path, X_OK) != -1)
		{
			free(tmp_cmd);
			return (tmp_path);
		}
		free(tmp_path);
	}
	return (NULL);
}

void	parse_to_arg(t_arg *arg)
{
	arg->path = get_path_envp(arg->envp);
	arg->cmd_arg1 = ft_split(arg->argv[2], ' ');//sed awk 예외
	arg->cmd_arg2 = ft_split(arg->argv[3], ' ');
	if (!arg->path || !arg->cmd_arg1 || !arg->cmd_arg2)
		exit_err(arg, "arg->argv split error\n", 1);
	arg->cmd1 = get_cmd_argv(arg->path, arg->cmd_arg1[0]);
	arg->cmd2 = get_cmd_argv(arg->path, arg->cmd_arg2[0]);
}
