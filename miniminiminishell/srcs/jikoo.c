#include "../includes/miniminiminishell.h"

void    add_envp_node(t_envp_node **envp_list, t_envp_node *new_envp_node)
{
    t_envp_node	*envp_list_ptr;

	if (!*envp_list)
	{
		*envp_list = new_envp_node;
		return ;
	}
	envp_list_ptr = *envp_list;
	while (envp_list_ptr->next)
		envp_list_ptr = envp_list_ptr->next;
	envp_list_ptr->next = new_envp_node;
}

static t_envp_node *create_envp_node(char *str)
{
    t_envp_node *envp_node;

    envp_node = malloc(sizeof(t_envp_node));
    if (!envp_node)
        return (NULL);
    envp_node->string = ft_strdup(str);
    envp_node->next = NULL;
    return (envp_node);
}

t_envp_node *init_envp_list(char **envp)
{
    t_envp_node *envp_list;

    envp_list = NULL;
    while (*envp)
        add_envp_node(&envp_list, create_envp_node(*envp++));
    return (envp_list);
}

void    free_envp_list(t_envp_node *envp_list)
{
    t_envp_node	*temp;

	while (envp_list)
	{
		temp = envp_list;
		envp_list = envp_list->next;
		free(temp->string);
		free(temp);
	}
}
