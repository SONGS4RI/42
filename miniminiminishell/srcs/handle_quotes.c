#include "../includes/miniminiminishell.h"

static char	**seperate_single_quotes(char *str, int start_idx, int end_idx)
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

// 문제야 문제 ... 1.str123 free 하고싶은데 못하게 함 ;;; 2.env가 NULL일 때 지랄
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

static char	*interpret_env_from_d_quotes(char *str)
{
	char	*str1;
	char	*str2;
	char	*str3;
	int		start_idx;
	int		end_idx;

	start_idx = 0;
	while (str[start_idx] && str[start_idx] != '$')
		start_idx++;
	if (str[start_idx] == '\0')
		return (str);
	end_idx = start_idx + 1;
	while (str[end_idx] && str[end_idx] != ' ')
		end_idx++;
	str1 = ft_substr(str, 0, start_idx);
	str2 = get_env(ft_substr(str, start_idx + 1, end_idx - start_idx - 1));
	str3 = ft_substr(str, end_idx, ft_strlen(str) - end_idx);
	free(str);
	return (multiple_join(str1, str2, str3));
}

static char	**seperate_double_quotes(char *str, int start_idx, int end_idx)
{
	char	**strs;

	strs = malloc(sizeof(char *) * 4);
	if (!strs)
		return (NULL);
	strs[0] = ft_substr(str, 0, start_idx);
	strs[1] = ft_substr(str, start_idx + 1, end_idx - start_idx - 1);
	strs[1] = interpret_env_from_d_quotes(strs[1]); // 환경변수 해석
	strs[2] = ft_substr(str, end_idx + 1, ft_strlen(str) - end_idx - 1);
	strs[3] = 0;
	return (strs);
}

static char	**seperate_quotes(char *str)
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
