#include "../../includes/miniminiminishell.h"

t_token	*lexical_analysis(t_info *info, char *input)
{
	t_token	*token_list;

	// 1. input -> chunk
	token_list = create_token(input, TOKEN_TYPE_CHUNK);
	// 2. handle quotes
	handle_quotes(info->env_list, token_list);
	// 3. handle environment variables
	handle_environment_variables(info, token_list);
	// 4. seperate space token
	seperate_token_by_arg(token_list, " ");
	// 5. seperate pipeline token
	seperate_token_by_arg(token_list, "|");
	// 6. seperate redirection toekn << < > >>
	seperate_token_by_arg(token_list, "<<");
	seperate_token_by_arg(token_list, ">>");
	seperate_token_by_arg(token_list, "<");
	seperate_token_by_arg(token_list, ">");
	// 7. remove empty chunk
	// 8. change chunk to argv
	return (token_list);
}
