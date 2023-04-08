#include "../../includes/miniminiminishell.h"

static t_env_node	*delete_env_list(t_env_node *env_list)
{
	t_env_node	*next;

	next = env_list->next;
	free(env_list->key);
	if (env_list->value)
		free(env_list->value);
	free(env_list);
	return (next);
}

static void	set_error_flag(char *str, int *error_flag)
{
	if (ft_isdigit(str[0]))
	{
		ft_putstr_fd("minishell: unset: \'", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
		*error_flag = 1;
	}
}

static int	do_unset(t_info *info, t_env_node *cur, t_env_node *prev, char *str)
{
	if (ft_strncmp(cur->key, str, ft_strlen(str)) == 0)
	{
		if (ft_strncmp(cur->key, "PATH", 4) == 0)
			free_2d_arr(info->path_list);
		if (prev == NULL)
			info->env_list = delete_env_list(cur);
		else
			prev->next = delete_env_list(cur);
		return (1);
	}
	return (0);
}

int	ms_unset(t_info *info, char **argv)
{
	t_env_node *cur;
	t_env_node *prev;
	int			idx;
	int			error_flag;

	idx = 0;
	error_flag = 0;
	while (argv[++idx])
	{
		set_error_flag(argv[idx], &error_flag);
	    cur = info->env_list;
		prev = NULL;
		while (cur)
		{
			if (do_unset(info, cur, prev, argv[idx]))
				break ;
			prev = cur;
			cur = cur->next;
		}
	}
	return (error_flag);
}
