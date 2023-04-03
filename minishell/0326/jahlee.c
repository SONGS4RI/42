#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../../libft/libft.h"

/*
expot A="echo 123"
{echo $A -n} => {echo }{echo}{ }{123}{ -n}
{echo "$A" -n} => {echo }{echo 123}{ -n}
*/

/*
{echo "$a" -n} => {echo }{echo 123}{ -n}
// export a="echo 123"
{echo $a -n} => {echo }{echo}{ }{123}{ -n}
// export b="echo a 123"
{echo $b -n} => {echo }{echo}{ }{a 123}{ -n}
{echo '$a' $a "$a" -n} => {echo }[$a]{ $a "$a" -n}
					   => {echo }[$a]{ $a }[echo 123]{ -n}
				 	   => {echo }[$a]{ }[echo][ ][123]{ }[echo 123]{ -n}
					   => {echo}[ ]{}[$a]{}[ ]{}[echo][ ][123]{}[ ]{}[echo 123]{}[ ]{-n}
					   => [echo][ ][$a][ ][echo][ ][123][ ][echo 123][ ][-n]
					   => [echo][$a][echo][123][echo 123][-n]
*/

/*
	echo "123 45 678"9 => 123 45 6789
	{echo }[123 45 678]{9}
	{echo}[ ]{}[123 45 678]{9}
	[echo][ ][123 45 678][9]
	[echo][ ][123 45 6789]
*/

/*{}:chunk, {-}:blank, []:argv
export a=123
echo "hi " | cat << '$a' -e >test |echo $a
1. quotes
{echo }[hi ]{ | cat << '$a' -e >test |echo $a}
{echo }[hi ]{ | cat << }[$a]{ -e >test |echo $a}
2. env
{echo }[hi ]{ | cat << }[$a]{ -e >test |echo }[123]{-}[]{}
3. blank
{echo}{-}{}[hi ]{}{-}{| cat << }[$a]{ -e >test |echo }[123]{-}[]{}
{echo}{-}{}[hi ]{}{-}{|}{-}{cat << }[$a]{ -e >test |echo }[123]{-}[]{}
{echo}{-}{}[hi ]{}{-}{|}{-}{cat}{-}{<< }[$a]{ -e >test |echo }[123]{-}[]{}
{echo}{-}{}[hi ]{}{-}{|}{-}{cat}{-}{<<}{-}{}[$a]{}{-}{-e >test |echo }[123]{-}[]{}
{echo}{-}{}[hi ]{}{-}{|}{-}{cat}{-}{<<}{-}{}[$a]{}{-}{-e}{-}{>test |echo }[123]{-}[]{}
{echo}{-}{}[hi ]{}{-}{|}{-}{cat}{-}{<<}{-}{}[$a]{}{-}{-e}{-}{>test}{-}{|echo }[123]{-}[]{}
{echo}{-}{}[hi ]{}{-}{|}{-}{cat}{-}{<<}{-}{}[$a]{}{-}{-e}{-}{>test}{-}{|echo}{-}{}[123]{-}[]{}
4. pipe
{echo}{-}{}[hi ]{}{-}{}{|}{}{-}{cat}{-}{<<}{-}{}[$a]{}{-}{-e}{-}{>test}{-}{}{|}{echo}{-}{}[123]{-}[]{}
5. redirection
{echo}{-}{}[hi ]{}{-}{}{|}{}{-}{cat}{-}{}{<<}{}{-}{}[$a]{}{-}{-e}{-}{}{>}{test}{-}{}{|}{echo}{-}{}[123]{-}[]{}
6. 빈 chunk 소각, 모든 chunk 를 argv_token 으로 치환
[echo]{-}[hi ]{-}[|]{-}[cat]{-}[<<]{-}[$a]{-}[-e]{-}{>}[test]{-}{|}[echo]{-}[123]{-}[]
7. 연속한 argv_token 병합
[echo]{-}[hi ]{-}[|]{-}[cat]{-}[<<]{-}[$a]{-}[-e]{-}{>}[test]{-}{|}[echo]{-}[123]{-}[]
8. space token 소각
[echo][hi ][|][cat][<<][$a][-e]{>}[test]{|}[echo][123][]
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

char	*change_env(char *string)
{

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
	strs[1] = change_env(ft_substr(str, start_idx + 1, end_idx - start_idx - 1)); // 환경변수 해석
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
	while (str[end_idx] && str[end_idx] != str[start_idx])
		end_idx++;
	if (str[end_idx] == '\'')
		return (seperate_single_quotes(str, start_idx, end_idx));
	else if (str[end_idx] == '\"')
		return (seperate_double_quotes(str, start_idx, end_idx));
	perror("quotes not pair");
	exit(1);
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
	token_list = create_token(input, TOKEN_TYPE_CHUNK);//맨처음 구문 통째로 chunk
	// 2. quotes
	handle_quotes(token_list);
	// 3. environment variable
	// 4. space
	// 5. pipeline
	// 6. redirection
	return (token_list);
}

int main(void)
{
	char	*input;
	t_token	*token_list;
	t_token	*tmp;

	input = readline("🥨 minishell$ ");
	if (input)
	{
		token_list = lexcial_analyze(input);
		tmp = token_list;
		while (tmp)
		{
			printf("{%s}(%d)\n", tmp->string,tmp->type);
			tmp = tmp->next;
		}
		// syntax_analyze();
		free(input);
	}
	return (0);
}

/*
cc -lreadline -L/Users/jahlee/.brew/Cellar/readline/8.2.1/lib -I/Users/jahlee/.brew/Cellar/readline/8.2.1/include jahlee.c ../libft.a -o jahlee
*/