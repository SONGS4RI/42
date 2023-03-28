#include "../../includes/environment_variables.h"

t_env_node	*create_env_node(char *str)
{
	t_env_node	*env_node;

	env_node = malloc(sizeof(t_env_node));
	if (!env_node)
		return (NULL);
	env_node->string = ft_strdup(str);
	env_node->next = NULL;
	return (env_node);
}

void	add_env_node(t_env_node **env_list, t_env_node *new_env_node)
{
	t_env_node	*env_list_ptr;

	if (!*env_list)
	{
		*env_list = new_env_node;
		return ;
	}
	env_list_ptr = *env_list;
	while (env_list_ptr->next)
		env_list_ptr = env_list_ptr->next;
	env_list_ptr->next = new_env_node;
}

t_env_node	*init_env_list(char **envp)
{
	t_env_node	*env_list;

	env_list = NULL;
	while (*envp)
		add_env_node(&env_list, create_env_node(*envp++));
	return (env_list);
}

char	*free_env_key_and_get_env_value(t_env_node *env_list, char *env_key)
{
	char	*env_value;

	while (env_list && ft_strncmp(env_list->string, env_key, ft_strlen(env_key)))
		env_list = env_list->next;
	if (env_list && *(env_list->string + ft_strlen(env_key)) == '=')
		env_value = env_list->string + ft_strlen(env_key) + 1;
	else
		env_value = NULL;
	free(env_key);
	if (env_value)
		return (ft_strdup(env_value));
	else
		return (ft_strdup(""));
}

void	free_env_list(t_env_node *env_list)
{
	t_env_node	*temp;

	while (env_list)
	{
		temp = env_list;
		env_list = env_list->next;
		free(temp->string);
		free(temp);
	}
}
