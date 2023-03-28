#include "../includes/miniminiminishell.h"

static void	initialize(t_info *info_ptr, char **envp)
{
	info_ptr->exit_status = 0;
	tcgetattr(STDIN_FILENO, &(info_ptr->ms_termios));
	(&info_ptr->ms_termios)->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &(info_ptr->ms_termios));
	info_ptr->env_list = init_env_list(envp);
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	info_ptr->path_list = ft_split(*envp + 5, ':');
	set_signal();
}

void	print_token_list(t_token *token_list) ///////////////
{
	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_CHUNK)
			printf(GREEN"{%s}"RESET, token_list->string);
		else if (token_list->type == TOKEN_TYPE_ARGV)
			printf(MAGENTA"[%s]"RESET, token_list->string);
		else if (token_list->type == TOKEN_TYPE_SPACE)
			printf(BLUE"[%s]"RESET, token_list->string);
		else if (token_list->type == TOKEN_TYPE_PIPELINE)
			printf(YELLOW"[%s]"RESET, token_list->string);
		else if (token_list->type == TOKEN_TYPE_REDIRECTION)
			printf(RED"[%s]"RESET, token_list->string);
		token_list = token_list->next;
	}
	printf("\n");
}

void	run_minishell(t_info *info)
{
	t_token	*token_list;
	char	*input;

	while (1)
	{
		input = readline("🍄 minishell$ ");
		if (!input) // ctrl + D
		{
			printf("\033[1A");
			printf("\033[14C");
			printf("exit\n");
			break ;
		}
		else if (*input != '\0')
		{
			token_list = lexical_analysis(info, input);
			printf("\n");
			// print_token_list(token_list); /////////////////////////////////////
			// syntax_analysis();
			free_token_list(token_list);
		}
		free(input);
	}
}

#include <stdlib.h>
void	check_leak(void)
{
	system("leaks miniminiminishell");
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	(void)argc;
	(void)argv;
	atexit(check_leak);
	initialize(&info, envp);
	run_minishell(&info);
	free_2d_arr(info.path_list);
	free_env_list(info.env_list);
	return (0);
}
