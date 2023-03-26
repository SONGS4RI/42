#include "../includes/miniminiminishell.h"

t_token	*lexcial_analysis(char *input)
{
	t_token	*token_list;

	// 1. input -> chunk
	token_list = create_token(input, TOKEN_TYPE_CHUNK);
	// 2. handle quotes
	handle_quotes(token_list);
	// 3. handle environment variables
	// handle_environment_variables(token_list);
	// 4. seperate space token
	// 5. seperate pipeline token
	// 6. seperate redirection toekn
	// 7. remove empty chunk
	// 8. change chunk to argv
	return (token_list);
}
