#include "../includes/miniminiminishell.h"

static void	init_info(t_info *info_ptr, char **envp)
{
	// termios 구조체 설정
	tcgetattr(STDIN_FILENO, &(info_ptr->ms_termios));
	(&info_ptr->ms_termios)->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &(info_ptr->ms_termios));
	// 환경변수 리스트, PATH 리스트 저장
	info_ptr->env_list = envp;
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	info_ptr->path_list = ft_split(*envp + 5, ':');
}

static void	signal_handler(int signum)
{
	if (signum == SIGINT)
		printf("🍄 minishell$ \n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

static void	set_signal(void)
{
	signal(SIGINT, signal_handler);	// ctrl + C
	signal(SIGQUIT, SIG_IGN);		// ctrl + "\"
}

void	print_token_list(t_token *token_list)
{
	printf("\n");
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
	printf("\n\n");
}

void	check_leak(void)
{
	system("leaks miniminiminishell | grep leaked");
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	t_token	*token_list;
	char	*input;

	(void)argc;
	(void)argv;
	atexit(check_leak);
	init_info(&info, envp);
	set_signal();
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
			token_list = lexcial_analysis(input);
			print_token_list(token_list);
			// syntax_analysis();
			free_token_list(token_list);
		}
		free(input);
	}
	free_2d_arr(info.path_list);
	return (0);
}
