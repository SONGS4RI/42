/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:47:41 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/20 22:08:45 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	set_pwd(t_info *info, char *key)
{
	char	**argv;
	char	current_working_dir[1024];

	argv = malloc(sizeof(char *) * 3);
	if (!argv)
		return ;
	getcwd(current_working_dir, 1024);
	argv[0] = ft_strdup("export");
	argv[1] = ft_strjoin(key, current_working_dir);
	argv[2] = 0;
	ms_export(info, argv);
	free_2d_arr(argv);
}

int	ms_cd(t_info *info, char **argv)
{
	char	*path;

	set_pwd(info, "OLDPWD=");
	if (argv[1] && (access(argv[1], F_OK) || chdir(argv[1])))
	{
		ms_error("cd", argv[1]);
		return (1);
	}
	if (argv[1] == NULL)
	{
		path = get_env_value_and_free_env_key(info->env_list,
				ft_strdup("HOME"));
		if (path[0] == '\0')
		{
			free(path);
			ft_putendl_fd("minishell: cd: HOME not set", STDERR_FILENO);
			return (1);
		}
		chdir(path);
		free(path);
	}
	set_pwd(info, "PWD=");
	return (0);
}
