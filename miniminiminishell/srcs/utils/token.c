#include "../../includes/token.h"

t_token	*create_token(char *string, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->origin_string = string;
	token->string = ft_strdup(string);
	token->type = type;
	token->next = NULL;
	return (token);
}

t_token	*add_token(t_token **token_list, t_token *new_token)
{
	t_token	*token_list_ptr;

	if (!*token_list)
	{
		*token_list = new_token;
		return (new_token);
	}
	token_list_ptr = *token_list;
	while (token_list_ptr->next)
		token_list_ptr = token_list_ptr->next;
	token_list_ptr->next = new_token;
	return (new_token);
}

void	delete_token(t_token *prev_token, t_token **del_token_ptr)
{
	t_token	*next_token;

	next_token = (*del_token_ptr)->next;
	free((*del_token_ptr)->string);
	(*del_token_ptr)->next = NULL;
	free(del_token_ptr);
	prev_token->next = next_token;
}

void	free_token_list(t_token **token_list_ptr)
{
	t_token	*temp;

	while (*token_list_ptr)
	{
		temp = (*token_list_ptr)->next;
		free((*token_list_ptr)->string);
		(*token_list_ptr)->next = NULL;
		free(*token_list_ptr);
		*token_list_ptr = temp;
	}
}
