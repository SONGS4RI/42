#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"

/*

{echo '$a' -n}
{echo } {$a} { -n}

*/

typedef enum e_token_type
{
	TOKEN_TYPE_CHUNK,
	TOKEN_TYPE_ARGV,
	TOKEN_TYPE_SPACE,
	TOKEN_TYPE_PIPELINE,
	TOKEN_TYPE_REDIRECTION
}	t_token_type;

typedef struct s_token
{
	char			*origin_string;
	char			*string;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

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
	token->origin_string = string;
	token->string = ft_strdup(string);
	token->type = type;
	token->next = NULL;
	return (token);
}

void	free_seperated_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

char	**seperate_single_quotes(char *str, int start_idx, int end_idx)
{
	char	**strs;

	strs = malloc(sizeof(char *) * 4);
	if (!strs)
		return (NULL);
	strs[0] = ft_substr(str, 0, start_idx);
	strs[1] = ft_substr(str, start_idx + 1, end_idx - start_idx - 1);
	strs[2] = ft_substr(str, end_idx + 1, ft_strlen(str) - end_idx - 1);
	strs[3] = 0;
	return (strs);
}

char	**seperate_double_quotes(char *str, int start_idx, int end_idx)
{
	char	**strs;

	strs = malloc(sizeof(char *) * 4);
	if (!strs)
		return (NULL);
	strs[0] = ft_substr(str, 0, start_idx);
	strs[1] = ft_substr(str, start_idx + 1, end_idx - start_idx - 1); // 환경변수 해석
	strs[2] = ft_substr(str, end_idx + 1, ft_strlen(str) - end_idx - 1);
	strs[3] = 0;
	return (strs);
}

char	**seperate_quotes(char *str)
{
	int	start_idx;
	int	end_idx;

	start_idx = 0;
	while (str[start_idx] && str[start_idx] != '\'' && str[start_idx] != '\"')
		start_idx++;
	if (str[start_idx] == '\0')
		return (NULL);
	end_idx = start_idx + 1;
	if (str[start_idx] == '\'' || str[start_idx] == '\"')
	{
		while (str[end_idx] && str[end_idx] != str[start_idx])
			end_idx++;
		if (str[end_idx] == '\'')
			return (seperate_single_quotes(str, start_idx, end_idx));
		else if (str[end_idx] == '\"')
			return (seperate_double_quotes(str, start_idx, end_idx));
	}
	return (NULL);
}

// CHUNK => CHUNK, ARGV, CHUNK
void	handle_quotes(t_token *token_list)
{
	char	**strs;

	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_CHUNK)
		{
			strs = seperate_quotes(token_list->string);
			if (strs)
			{
				free(token_list->string);
				token_list->string = ft_strdup(strs[0]);
				add_token(&token_list, create_token(strs[1], TOKEN_TYPE_ARGV));
				add_token(&token_list, create_token(strs[2], TOKEN_TYPE_CHUNK));
				free_seperated_strs(strs);
			}
		}
		token_list = token_list->next;
	}
}

t_token	*lexcial_analyze(char *input)
{
	t_token	*token_list;

	// 1. input -> chunk
	token_list = create_token(input, TOKEN_TYPE_CHUNK);
	// 2. quotes
	handle_quotes(token_list);
	// 3. environment variable
	// 4. space
	// 5. pipeline
	// 6. redirection
	while (token_list)
	{
		printf("{%s}\n", token_list->string);
		token_list = token_list->next;
	}
	return (token_list);
}

int main(void)
{
	char	*input;
	t_token	*token_list;

	input = readline("🥨 minishell$ ");
	if (input)
	{
		token_list = lexcial_analyze(input);
		// syntax_analyze();
		free(input);
	}
	return (0);
}