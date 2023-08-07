/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:02:41 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/17 16:46:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	**get_path_envp(char **envp)
{
	char	*path;

	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	path = *envp + 5;
	return (ft_split(path, ':'));
}

static char	*get_cmd_argv(char **path, char *cmd)
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

static int	set_cmd(t_arg *arg, int j)
{
	int	i;
	int	size;

	size = arg->argc - (1 + j);
	arg->cmd_cnt = size - 1;
	i = -1;
	arg->cmd_arg = (char ***)malloc(sizeof(char **) * size);
	if (!arg->cmd_arg)
		return (1);
	arg->cmd = (char **)malloc(sizeof(char *) * size);
	if (!arg->cmd)
		return (1);
	while (++j < arg->argc - 1)
		arg->cmd_arg[++i] = ft_pipex_split(arg->argv[j], ' ', 0);
	arg->cmd_arg[++i] = NULL;
	i = -1;
	while (++i < size - 1)
	{
		if (!arg->cmd_arg[i])
			return (1);
		arg->cmd[i] = get_cmd_argv(arg->path, arg->cmd_arg[i][0]);
	}
	arg->cmd[i] = NULL;
	return (0);
}

void	parse_to_arg(t_arg *arg)
{
	int		i;

	i = -1;
	arg->path = get_path_envp(arg->envp);
	if (!arg->path)
		exit_err(arg, "envp error", 1);
	if (!ft_strncmp(arg->argv[1], "here_doc", ft_strlen(arg->argv[1])))
	{
		arg->here_doc = 1;
		if (arg->argc < 6)
			exit_err(arg, "Wrong Usage", 1);
	}
	arg->init_err = set_cmd(arg, arg->here_doc + 1);
}
