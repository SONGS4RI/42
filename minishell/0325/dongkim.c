#include <stdbool.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"

/**
 * 1. quote 해석 -> ", '
 * 2. $ 환경변수 해석
 * 3. 공백 분리
 * 4. 연산자 (파이프, 리다이렉션) 분리
 * 5. 연속된 argv 병합
 * 6. 공백 소각
 */

typedef struct s_data
{
	char			*original_str;
	int				single_quote;
	int				double_quote;
	struct s_node	*front;
}	t_data;

typedef struct s_node
{
	char			*token;
	struct s_node	*next;
}	t_node;

// |echo "aaa $a"|
// |echo aaa 123|

// |echo "aaa $a"|
// |echo |+|aaa $a| => |echo |+|aaa | + |123|
// |echo aaa 123|
// |echo|, | |, |aaa|, | |, |$a|
// |echo|, | |, |aaa|, | |, |123|
// |echo aaa 123|

t_node	*make_node(char *token)
{
	t_node	*res;

	res = (t_node*)malloc(sizeof(t_node));
	res->token = token;
	res->next = 0;
	return (res);
}

int	is_single_quo(char c)
{
	if (c == '\'')
		return (1);
	return (0);
}

int	is_double_quo(char c)
{
	if (c == '\"')
		return (1);
	return (0);
}

void	tokennize(t_data *data, char *input)
{
	t_node	*cur;

	data->front = make_node(0); // 노드 만들어서 front가리키게 해주기
	cur = data->front;
	int	i = -1, start_i = 0;
	while (input[++i])
	{
		if (is_single_quo(input[i]) && data->double_quote == 0)
		{
			cur->next = make_node(ft_substr(input, start_i, i - start_i));
			cur = cur->next;
			if (data->single_quote)
				data->single_quote -= 1;
			else
				data->single_quote += 1;
			start_i = i + 1;
		}
		else if (is_double_quo(input[i]) && data->single_quote == 0)
		{
			cur->next = make_node(ft_substr(input, start_i, i - start_i));
			cur = cur->next;
			if (data->double_quote)
				data->double_quote -= 1;
			else
				data->double_quote += 1;
			start_i = i + 1;
		}
	}
	cur->next = make_node(ft_substr(input, start_i, i - start_i));
	cur = cur->next;
	cur = data->front;
	cur = cur->next;
	free(data->front);
	data->front = cur;
}

void	print_node(t_node *first)
{
	while (first)
	{
		printf("|%s|\n", first->token);
		first = first->next;
	}
}

int	main(void)
{
	char	*input;
	t_data	*data;

	input = readline("🥨 minishell$ ");
	data = (t_data*)malloc(sizeof(t_data));
	data->original_str = input;
	data->single_quote = 0;
	data->double_quote = 0;
	tokennize(data, input);
	print_node(data->front);
	free(input);
	return (0);
}
