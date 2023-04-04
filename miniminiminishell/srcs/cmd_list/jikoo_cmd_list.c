#include "../../includes/miniminiminishell.h"

t_redirection	*create_redirection(char *type, char *file)
{
	t_redirection	*redirection;

	redirection = malloc(sizeof(t_redirection));
	if (!redirection)
		return (NULL);
	redirection->type = ft_strdup(type);
	redirection->file = ft_strdup(file);
	redirection->next = NULL;
	return (redirection);
}

void	add_redirection(t_redirection **redirection_list, t_redirection *new_redirection)
{
	t_redirection	*redirection_list_ptr;

	if (!*redirection_list)
	{
		*redirection_list = new_redirection;
		return ;
	}
	redirection_list_ptr = *redirection_list;
	while (redirection_list_ptr->next)
		redirection_list_ptr = redirection_list_ptr->next;
	redirection_list_ptr->next = new_redirection;
}

t_redirection	*create_redirection_list(t_token **token_list)
{
	t_redirection	*redirection_list;
	t_token			*cur_token;

	redirection_list = NULL;
	cur_token = *token_list;
	while (cur_token && cur_token->type != TOKEN_TYPE_PIPELINE)
	{
		if (cur_token->type == TOKEN_TYPE_REDIRECTION)
		{
			add_redirection(&redirection_list, create_redirection(cur_token->string, cur_token->next->string));
			delete_token(cur_token, token_list);
			cur_token = delete_token(cur_token, token_list);
		}
		else
			cur_token = cur_token->next;
	}
	return (redirection_list);
}

static int  get_argv_cnt(t_token *token_list)
{
	int	cnt;

	cnt = 0;
	while (token_list && token_list->type != TOKEN_TYPE_PIPELINE)
	{
		cnt++;
		token_list = token_list->next;
	}
	return (cnt);
}

char    **create_argv(t_token **token_list)
{
	char	**argv;
	t_token	*cur_token;
	int		idx;
	int		cnt;

	cnt = get_argv_cnt(*token_list);
	argv = malloc(sizeof(char *) * (cnt + 1));
	if (!argv)
		return (NULL);
	idx = -1;
	cur_token = *token_list;
	while (++idx < cnt)
	{
		argv[idx] = ft_strdup(cur_token->string);
		cur_token = delete_token(cur_token, token_list);
	}
	argv[idx] = 0;
	return (argv);
}

t_cmd   *create_cmd(t_token **token_list)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->prev = NULL;
	cmd->next = NULL;
	cmd->redirection = create_redirection_list(token_list);
	cmd->argv = create_argv(token_list);
	return (cmd);
}

void    add_cmd(t_cmd **cmd_list, t_cmd *new_cmd) // prev 해결해야함
{
	t_cmd	*cmd_list_ptr;

	if (!*cmd_list)
	{
		*cmd_list = new_cmd;
		return ;
	}
	cmd_list_ptr = *cmd_list;
	while (cmd_list_ptr->next)
		cmd_list_ptr = cmd_list_ptr->next;
	cmd_list_ptr->next = new_cmd;
}

void	print_cmd_list(t_cmd *cmd_list)
{
	int	i;

	while (cmd_list)
	{
		printf("argv = ");
		i = -1;
		while (cmd_list->argv[++i])
			printf("[%s] ", cmd_list->argv[i]);
		printf("\n");
		cmd_list = cmd_list->next;
	}
}

t_cmd	*create_cmd_list(t_token **token_list)
{
	t_cmd	*cmd_list;
	t_token	*cur_token;

	cmd_list = NULL;
	cur_token = *token_list;
	while (cur_token)
	{
		add_cmd(&cmd_list, create_cmd(token_list));
		print_token_list(*token_list);
		print_cmd_list(cmd_list);
		cur_token = *token_list;
		if (cur_token->type == TOKEN_TYPE_PIPELINE)
		{
			cur_token = delete_token(cur_token, token_list);
			print_token_list(*token_list);
		}
		else
			cur_token = cur_token->next;
	}
	return (cmd_list);
}