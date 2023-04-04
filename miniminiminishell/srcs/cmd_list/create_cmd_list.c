#include "../../includes/miniminiminishell.h"

static t_cmd	*make_cmd_node(void)
{
	t_cmd	*cmd_node;
	
	cmd_node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd_node)
		return (NULL);
	cmd_node->argv = NULL;
	cmd_node->redirection = NULL;
	cmd_node->prev = NULL;
	cmd_node->next = NULL;
	return (cmd_node);
}

static char	**fill_argv(t_token *token_list)
{
	int		size;
	t_token *tmp;
	char 	**argv;

	size = 0;
	tmp = token_list;
	while (tmp && tmp->type != TOKEN_TYPE_PIPELINE)
	{
		if (tmp->type == TOKEN_TYPE_ARGV)
			size++;
		else if (tmp->type == TOKEN_TYPE_REDIRECTION)
			size--;
		tmp = tmp->next;
	}
	argv = (char **)malloc(sizeof(char *) * (size + 1));
	if (!argv)
		return (NULL);
	size = 0;
	while (token_list && token_list->type != TOKEN_TYPE_PIPELINE)
	{
		if (token_list->type == TOKEN_TYPE_ARGV)
			argv[size++] = ft_strdup(token_list->string);
		else if (token_list->type == TOKEN_TYPE_REDIRECTION)
			token_list = token_list->next;
		token_list = token_list->next;
	}
	argv[size] = NULL;
	return (argv);
}

static t_redirection	*make_redirection_node(t_token *token_list)
{
	t_redirection	*node;

	node = (t_redirection *)malloc(sizeof(t_redirection));
	node->type = ft_strdup(token_list->string);
	node->file = ft_strdup(token_list->next->string);
	node->next = NULL;
	return (node);
}

static void	fill_redirection(t_token *token_list, t_cmd **cmd_list)
{
	t_redirection *cur;
	
	if (!(*cmd_list)->redirection)
		(*cmd_list)->redirection = make_redirection_node(token_list);
	else
	{
		cur = (*cmd_list)->redirection;
		while (cur->next)
			cur = cur->next;
		cur->next = make_redirection_node(token_list);
	}
}

t_cmd	*create_cmd_list(t_token *token_list)
{
	t_cmd	*cmd_list;
	t_cmd	*head;

	cmd_list = make_cmd_node();
	head = cmd_list;
	while (token_list)
	{
		if (cmd_list->argv == NULL  && token_list->type == TOKEN_TYPE_ARGV)
			cmd_list->argv = fill_argv(token_list);
		else if (token_list->type == TOKEN_TYPE_REDIRECTION)
		{
			fill_redirection(token_list, &cmd_list);
			token_list = token_list->next;
		}
		else if (token_list->type == TOKEN_TYPE_PIPELINE)
		{
			cmd_list->next = make_cmd_node();
			cmd_list = cmd_list->next;
		}
		token_list = token_list->next;
	}
	return (head);
}
