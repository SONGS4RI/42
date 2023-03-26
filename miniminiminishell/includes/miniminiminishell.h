#ifndef MINIMINIMINISHELL_H
# define MINIMINIMINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"

typedef enum e_token_type
{
	TOKEN_TYPE_CHUNK,               // 해석의 가능성이 있음, 하나 이상의 CHUNK 또는 TOKEN으로 나뉠 수 있음
	TOKEN_TYPE_ARGV,                // 따옴표 또는 환경변수 처리 완료, 더이상 해석되지 않음
	TOKEN_TYPE_SPACE,               // 공백 ' '
	TOKEN_TYPE_PIPELINE,            // 파이프라인 |
	TOKEN_TYPE_REDIRECTION          // 리다이렉션 <<, <, >, >>
}	t_token_type;

typedef struct s_token
{
	char			*origin_string; // 원형 보존을 위해 필요
	char			*string;        // (따옴표와 환경변수 해석이 완료된) 문자열
	t_token_type	type;
	struct s_token	*next;
}	t_token;

typedef struct s_info
{
    struct termios  ms_termios;
    char            **env_list;
    char            **path_list;
}   t_info;

/* token.c */
void	add_token(t_token **token_list, t_token *new_token);
t_token	*create_token(char *string, t_token_type type);
void    free_token_list(t_token *token_list);

/* lexcial_analysis.c */
t_token	*lexcial_analysis(char *input);

/* handle_quotes.c */
void	handle_quotes(t_token *token_list);

/* handle_environment_variables.c  */
char	*get_env(char *name);

/* utils.c */
void	ms_error(char *message);
void	free_2d_arr(char **arr);

#endif