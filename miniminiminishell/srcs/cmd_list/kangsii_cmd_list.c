t_cmd	*make_cmd(t_token *token)
{
	t_cmd	*cmd_node;
	
	cmd_node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd_list)
		return (NULL);
	cmd_node->argv = NULL;
	cmd_node->redirection = NULL;
	cmd_node->prev = NULL;
	cmd_node->next = NULL;
	return (cmd_node);
}

t_cmd	*make_redirection(t_token *token_re, t_token *token_fn)
{
	t_redirection	*node;

	node = (t_redirection *)malloc(sizeof(t_redirection));
	node->type = ft_strdup(token_re->string);
	node->file = ft_strdup(token_fn->string);
	node->next = NULL;
}

t_cmd	*create_cmd_list(t_cmd *cmd_node)
{
	t_cmd	*cmd_list;
	t_cmd	*head;
	t_cmd	*temp;
    int		i;

    cmd_list = make_cmd(); //초기화
    head = cmd_list;
	while (token_list)
	{
        i = 0;
        while (token_list->type != TOKEN_TYPE_PIPELINE)
		{
			if (token_list->type == TOKEN_TYPE_REDIRECTIN)
			{
				make_redirection(token_list, token_list->next);
				token_list = token_list->next->next;
			}
			else
			{
				cmd_list.argv[i] = ft_strdup(token_list->string);
				token_list = token_list->next;
				i++;
			}
		}
		temp = cmd_list;
		cmd_list = make_cmd();
		temp->next = cmd_list;
		cmd_list->prev = temp;
		token_list = token_list->next;
	}
	return (head);
}