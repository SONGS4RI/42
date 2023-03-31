#include "../../includes/token.h"

t_token	*create_token(char *string, t_token_type type) // 노드 만들기
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->string = ft_strdup(string);
	token->type = type;
	token->next = NULL;
	return (token);
}

t_token	*add_token(t_token **token_list, t_token *new_token) // 토큰 리스트가 없으면 
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

// del_token이 token_list의 맨 처음이었다면 del_token free하고 token_list의 주소를 del_token->next로 바꿔줌
// del_token을 지워주고 del_token->next를 리턴
t_token	*delete_token(t_token *del_token, t_token **token_list)
{
	t_token *prev;
	t_token *cur;

	if (del_token == *token_list)
	{
		free(del_token->string);
		del_token = del_token->next;
		free(*token_list);
		*token_list = del_token;
		return (del_token);
	}
	cur = *token_list;
	while (cur != del_token)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	free(cur->string);
	free(cur);
	return (prev->next);
}

void	free_token_list(t_token *token_list_ptr)
{
	t_token	*temp;

	while (token_list_ptr)
	{
		temp = token_list_ptr->next;
		free(token_list_ptr->string);
		free(token_list_ptr);
		token_list_ptr = temp;
	}
}
