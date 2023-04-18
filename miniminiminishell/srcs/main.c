#include "../includes/miniminiminishell.h"

static void	set_old_pwd(t_info *info)
{
	char	**argv;

	argv = malloc(sizeof(char *) * 3);
	if (!argv)
		return ;
	argv[0] = ft_strdup("");
	argv[1] = ft_strdup("OLDPWD");
	argv[2] = NULL;
	ms_unset(info, argv);
	ms_export(info, argv);
	free_2d_arr(argv);
}

static void	initialize(t_info *info_ptr, char **envp)
{
	info_ptr->stdin = dup(STDIN_FILENO);
	info_ptr->stdout = dup(STDOUT_FILENO);
	tcgetattr(STDIN_FILENO, &(info_ptr->ms_termios));
	(&info_ptr->ms_termios)->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &(info_ptr->ms_termios));
	info_ptr->env_list = init_env_list(envp);
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	info_ptr->path_list = ft_split(*envp + 5, ':');
	set_old_pwd(info_ptr);
}

void	print_token_list(t_token *token_list)///////////////
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

void	print_cmd_list(t_cmd *cmd_list)
{
	int	i;
	t_redirection	*cur;

	while (cmd_list)
	{
		if (cmd_list->argv)
		{
			printf("argv = ");
			i = -1;
			while (cmd_list->argv[++i])
				printf("[%s] ", cmd_list->argv[i]);
			printf("\n");
		}
		cur = cmd_list->redirection;
		while (cur)
		{
			printf("redirection = t: %s, f: %s\n", cur->type, cur->file);////
			cur = cur->next;
		}
		cmd_list = cmd_list->next;
	}
}

void	run_minishell(t_info *info)
{
	t_token	*token_list;
	t_cmd	*cmd_list;
	char	*input;

	while (1)
	{
		set_signal();//확인
		cmd_list = NULL;
		input = readline(CYAN"💎 minishell-1.0$ "RESET);
		if (!input) // ctrl + D
		{
			ft_putstr_fd("\033[1A\033[18C", STDOUT_FILENO);
			ms_exit(info, cmd_list);
		}
		else if (*input != '\0')
		{
			add_history(input);
			info->syntax_error = 0;
			token_list = lexical_analysis(info, input);
			if (!info->syntax_error)
				info->syntax_error = syntax_analysis(token_list);
			if (!info->syntax_error && token_list)
				cmd_list = create_cmd_list(token_list);
			free_token_list(token_list);
			if (cmd_list)
			{
				ms_execute(info, cmd_list);
				free_cmd_list(&cmd_list);
			}
		}
		free(input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	(void)argc;
	(void)argv;
	initialize(&info, envp);
	// printf("💖💫🌷🌼🐰🧸🎀🥨헬로🏅가이즈🌈🍟🍣✨💖\n");////////////////////////
	printf("\nAs beautiful as a shell🐚\n");
	printf("By: jikoo jahlee donghyk2 seokang\n");
	run_minishell(&info);
	return (0);
}
