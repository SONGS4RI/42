#include "../../includes/miniminiminishell.h"

static int	is_tokenable_sep(char c)
{
	return (c == ' ' || c == '|' || c == '<' || c == '>' || c == '\0');
}

static int	set_limiter_idx(char *str, int *start_idx, int *end_idx)
{
	if (is_tokenable_sep(str[*start_idx])) // limiter 없음
		return (0);
	*end_idx = *start_idx;
	if (str[*start_idx] == '\'' || str[*start_idx] == '\"')
	{
		*end_idx += 1;
		while (str[*end_idx] && str[*end_idx] != str[*start_idx])
			*end_idx += 1;
		if (str[*end_idx] && str[*end_idx] == str[*start_idx])
			*end_idx += 1;
	}
	else
		while (!is_tokenable_sep(str[*end_idx]) && str[*end_idx] != '\'' 
		&& str[*end_idx] != '\"')
			*end_idx += 1;
	return (1);
}

static int	set_quotes_idx(char *str, int *start_idx, int *end_idx)
{
	*start_idx = 0;
	*end_idx = -1;
	while (str[*start_idx] && str[*start_idx] != '\'' && str[*start_idx] != '\"')
		*start_idx += 1;
	if (str[*start_idx] == '\0')
		return (0);
	*end_idx = *start_idx + 1;
	while (str[*end_idx] && str[*end_idx] != str[*start_idx])
		*end_idx += 1;
	if (str[*end_idx] == '\0')
	{
		perror("handle_heredoc_limiter: quotes error\n");
		return (0);
	}
	return (1);
}

static char	*handle_limiter(char *limiter)
{
	char	*strs[3];
	int		start_idx;
	int		end_idx;
;
	if (!set_quotes_idx(limiter, &start_idx, &end_idx))
		return (limiter);
	strs[0] = ft_substr(limiter, 0, start_idx);
	strs[1] = ft_substr(limiter, start_idx + 1, end_idx - start_idx - 1);
	strs[2] = ft_substr(limiter, end_idx + 1, ft_strlen(limiter) - end_idx - 1);
	free(limiter);
	return (join_strs(strs[0], strs[1], strs[2]));
}

static char	**seperate_limiter(char *str, int start_idx)
{
	char	**strs;
	char	*temp1;
	char	**temp2;
	int		end_idx;

	if (start_idx == -1 || !set_limiter_idx(str, &start_idx, &end_idx))
		return (NULL);
	strs = malloc(sizeof(char *) * 4);
	if (!strs)
		return (NULL);
	strs[0] = ft_substr(str, 0, start_idx);
	strs[1] = handle_limiter(ft_substr(str, start_idx, end_idx - start_idx));
	strs[2] = ft_substr(str, end_idx, ft_strlen(str) - end_idx);
	while (!is_tokenable_sep(strs[2][0]))
	{
		temp2 = seperate_limiter(strs[2], 0); // {X}[]{}
		temp1 = join_strs(strs[1], temp2[1], ft_strdup(""));
		free_strs(strs[1], strs[2], NULL, NULL);
		strs[1] = temp1;
		strs[2] = ft_strdup(temp2[2]);
		free_2d_arr(temp2);
	}
	strs[3] = 0;
	return (strs);
}

static int	check_heredoc(char *str) // heredoc 아니면 -1, 맞으면 limiter 시작 인덱스 반환
{
	int	idx;

	idx = 0;
	while (str[idx] && str[idx] != '<')
		idx++;
	if (str[idx] == '\0' || ft_strncmp(str + idx, "<<", 2)) // heredoc 아님
		return (-1);
	idx += 2;
	while (str[idx] && str[idx] == ' ') // 공백 밀기
		idx += 1;
	return (idx);
}

static void	convert_result_to_token(t_token *token_list, char **strs)
{
	t_token	*temp;

	temp = token_list->next;
	token_list->next = NULL;
	free(token_list->string);
	token_list->string = ft_strdup(strs[0]);
	add_token(&token_list, create_token(strs[1], TOKEN_TYPE_ARGV));
	token_list = add_token(&token_list, create_token(strs[2], TOKEN_TYPE_CHUNK));
	free_2d_arr(strs);
	token_list->next = temp;
}

void	handle_heredoc_limiter(t_token *token_list)
{
	char	**strs;

	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_CHUNK)
		{
			strs = seperate_limiter(token_list->string, check_heredoc(token_list->string));
			if (strs)
				convert_result_to_token(token_list, strs);
		}
		token_list = token_list->next;
	}
}
