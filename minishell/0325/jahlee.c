#include <stdbool.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"

typedef struct s_token_list
{
	struct s_token	*front;
	struct s_token	*back;
}	t_token_list;

typedef struct s_token
{
	char			*token;
	struct s_token	*next;
}	t_token;

void	add_token(char *s, t_token_list *list)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return ;
	new->token = s;
	new->next = NULL;
	if (!list->front)
		list->front = new;
	else
		list->back->next = new;
	list->back = new;
}

int	do_single_quote(char *s, int start, t_token_list *list)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != '\'')
		i++;
	if (s[start + i] == '\'')
		add_token(ft_substr(s, start, i), list);
	return (start + i + 1);
}

int	do_double_quote(char *s, int start, t_token_list *list)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != '\"')
		i++;
	if (s[start + i] == '\"')
		add_token(ft_substr(s, start, i), list);
	return (start + i + 1);
}

// int	do_double_quote_env(char *s, int start, t_token_list *list)
// {
// 	int				offset;
// 	t_token_list	env;

// 	offset = 0;
// 	while (s[start + offset])
// 	{
// 		if (s[start + offset] == '$')
// 		{
// 			add_token(ft_substr(s, start, offset), list);
// 			start = get_env();
// 			offset = 0;
// 		}
// 		else
// 			offset++;
// 	}
// 	if (s[start + offset] == '\"')
// 		add_token(ft_substr(s, start, offset), list);
// 	else
// 		return (-1);
// 	return (start + offset + 1);
// }

void	do_quote_work(char *s, t_token_list *list, int start, int offset)
{
	while (s[start + offset])
	{
		if (s[start + offset] == '\'' || s[start + offset] == '\"')
		{
			add_token(ft_substr(s, start, offset), list);
			if (s[start + offset] == '\'')
				start = do_single_quote(s, start + offset + 1, list);// echo "hi" -n
			else
				start = do_double_quote(s, start + offset + 1, list);
			offset = 0;
		}
		else
			offset++;
	}
	add_token(ft_substr(s, start, offset), list);
}

int	main(void)
{
	char			*input;
	t_token_list	list;
	t_token			*tmp;

	list.front = NULL;
	list.back = NULL;

	input = readline("🥨 minishell$ ");
	do_quote_work(input, &list, 0, 0);

	tmp = list.front;
	printf("=============result================\n");
	while (tmp->next)
	{
		printf("|%s|\n",tmp->token);
		tmp = tmp->next;
	}
	printf("|%s|\n",tmp->token);
	free(input);
	// printf("env test\n%s\n",getenv("1"));
	return (0);
}
//-lreadline -L/Users/jahlee/.brew/Cellar/readline/8.2.1/lib -I/Users/jahlee/.brew/Cellar/readline/8.2.1/include

//cc -lreadline -L/Users/jahlee/.brew/Cellar/readline/8.2.1/lib -I/Users/jahlee/.brew/Cellar/readline/8.2.1/include jahlee.c libft.a -o jahlee