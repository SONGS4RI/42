#include "../../includes/miniminiminishell.h"

void	handle_chunk(t_token *token_list)
{
	t_token *head;

	head = token_list;
	while(token_list)
	{
		if (token_list->type == TOKEN_TYPE_CHUNK)
		{
			if (token_list->string[0] != '\0')
			{
				token_list->type = TOKEN_TYPE_ARGV;
				token_list = token_list->next;
			}
			else
				token_list = delete_token(token_list, head);
		}
		else
			token_list = token_list->next;
	}
}
