#include "../includes/miniminiminishell.h"

void	add_token(t_token **token_list, t_token *new_token)
{
	t_token	*token_list_ptr;

	if (!*token_list)
	{
		*token_list = new_token;
		return ;
	}
	token_list_ptr = *token_list;
	while (token_list_ptr->next)
		token_list_ptr = token_list_ptr->next;
	token_list_ptr->next = new_token;
}

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

void	free_token_list(t_token *token_list)
{
	t_token	*temp;

	while (token_list)
	{
		temp = token_list;
		token_list = token_list->next;
		free(temp->string);
		free(temp);
	}
}
