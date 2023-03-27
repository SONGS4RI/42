#include "../includes/miniminiminishell.h"

static char	*multiple_join(char *str1, char *str2, char *str3)
{
	char	*str;
	int		size;
	int		i;

	size = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*str1)
		str[i++] = *str1++;
	while (*str2)
		str[i++] = *str2++;
	while (*str3)
		str[i++] = *str3++;
	str[size] = '\0';
	return (str);
}

// echo "hello $USER 42" -n
// {hello $USER 42} => {hello jikoo 42}

// echo "hello" -n
// {hello}
static char	*interpret_env_from_d_quotes(char *str)
{
	char	*str1;
	char	*str2;
	char	*str3;
	int		dollar_idx;
	int		next_idx;

	dollar_idx = 0;
	while (str[dollar_idx] && str[dollar_idx] != '$')
		dollar_idx++;
	if (str[dollar_idx] == '\0')
		return (str);
	next_idx = dollar_idx + 1;
	while (str[next_idx] && str[next_idx] != ' ' && str[next_idx] != '\'')
		next_idx++;
	str1 = ft_substr(str, 0, dollar_idx);
	str2 = free_and_getenv(ft_substr(str, dollar_idx + 1, next_idx - dollar_idx - 1));
	str3 = ft_substr(str, next_idx, ft_strlen(str) - next_idx);
	free(str);
	str = multiple_join(str1, str2, str3);
	free(str1);
	free(str2);
	free(str3);
	return (str);
}

static void	set_quotes_idxs(char *str, int *start_idx, int *end_idx)
{
	*start_idx = 0;
	while (str[*start_idx] && str[*start_idx] != '\'' && str[*start_idx] != '\"')
		*start_idx += 1;
	if (str[*start_idx] == '\0')
		return ;
	*end_idx = *start_idx + 1;
	while (str[*end_idx] && str[*end_idx] != str[*start_idx])
		*end_idx += 1;
	if (str[*end_idx] == '\0')
	{
		perror("quotes error");
		// 여기 처리해줘야 함
	}
}

static char	**seperate_quotes(char *str)
{
	char	**strs;
	int		start_idx;
	int		end_idx;

	start_idx = -1;
	end_idx = -1;
	set_quotes_idxs(str, &start_idx, &end_idx);
	if (start_idx >= end_idx)
		return (NULL);
	strs = malloc(sizeof(char *) * 4);
	if (!strs)
		return (NULL);
	strs[0] = ft_substr(str, 0, start_idx);
	strs[1] = ft_substr(str, start_idx + 1, end_idx - start_idx - 1);
	if (str[start_idx] == '\"')
		strs[1] = interpret_env_from_d_quotes(strs[1]); // 환경변수 해석
	strs[2] = ft_substr(str, end_idx + 1, ft_strlen(str) - end_idx - 1);
	strs[3] = 0;
	return (strs);
}

void	handle_quotes(t_token *token_list)
{
	char	**strs;

	while (token_list)
	{
		// CHUNK => CHUNK, ARGV, CHUNK
		if (token_list->type == TOKEN_TYPE_CHUNK)
		{
			strs = seperate_quotes(token_list->string);
			if (strs)
			{
				free(token_list->string);
				token_list->string = ft_strdup(strs[0]);
				add_token(&token_list, create_token(strs[1], TOKEN_TYPE_ARGV));
				add_token(&token_list, create_token(strs[2], TOKEN_TYPE_CHUNK));
				free_2d_arr(strs);
			}
		}
		token_list = token_list->next;
	}
}
