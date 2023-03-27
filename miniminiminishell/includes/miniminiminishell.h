#ifndef MINIMINIMINISHELL_H
# define MINIMINIMINISHELL_H

# include <stdio.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "./environment_variables.h"
# include "./token.h"

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"

typedef struct s_info
{
    struct termios  ms_termios;
    t_env_node		*env_list;
    char            **path_list;
}   t_info;

t_token	*lexical_analysis(t_env_node *env_list, char *input);
void	handle_environment_variables(t_env_node *env_list, t_token *token_list);
void	handle_quotes(t_env_node *env_list, t_token *token_list);

void	set_signal(void);
void	free_2d_arr(char **arr);

#endif