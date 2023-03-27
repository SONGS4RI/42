#include "../includes/miniminiminishell.h"

int	cmp_env_key(char *string, char *envp_string)
{
	int i;

	i = -1;
	while (string[++i])
	{
		if (string[i] != envp_string[i])
			return (0);
	}
	if (envp_string[i] != '=')
		return (0);
	return (1);
}

char *my_getenv(char *name, t_envp_node *node)
{
	while (node)
	{
		if (cmp_env_key(name, node->string))
			return(node->string + ft_strlen(name) + 1);
		node = node->next;
	}
	return (NULL);
}

// int main()
// {
// 	t_envp_node node1;
// 	t_envp_node node2;
// 	t_envp_node node3;
	
// 	node1.next = &node2;
// 	node2.next = &node3;
// 	node3.next = NULL;
	
// 	node1.string = "abc=123";
// 	node2.string = "abcc=123123";
// 	node3.string = "aabc=123123123";
	
// 	printf("res: |%s|\n",my_getenv("aa bc",&node1));
// }
