#include "../../includes/miniminiminishell.h"

void	ms_error(char *blame, char *blame2)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(blame, STDERR_FILENO);
	if (blame2)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(blame2, STDERR_FILENO);
	}
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

static void	signal_handler(int signum)
{
	(void)signum;
	printf("🍄 minishell$ \n");
	g_exit_status = 1;
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	parent_handler(int signum)
{
	(void)signum;
	printf("\n");
}

///////오ㅐ냐면 우리 히어독 핸들러만들었더니 쓸모 없어졌어! 에이씨 퉤
void	child_handler(int signum)///////////뺼까말까 마지막에 결정해!!
{
	(void)signum;
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	set_signal(void)
{
	signal(SIGINT, signal_handler);	// ctrl + C
	signal(SIGQUIT, SIG_IGN);		// ctrl + "\"
}

int	is_tokenable_sep(char c)
{
	return (c == ' ' || c == '|' || c == '<' || c == '>' || c == '\0');
}

void	free_2d_arr(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
		free(arr);
	}
}

void    free_strs(char *str1, char *str2, char *str3, char *str4)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	if (str3)
		free(str3);
	if (str4)
		free(str4);
}

char	*join_strs(char *str1, char *str2, char *str3)
{
	char	*str;
	int		size;
	int		i;

	size = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (str1)
		while (*str1)
			str[i++] = *str1++;
	if (str2)
		while (*str2)
			str[i++] = *str2++;
	if (str3)
		while (*str3)
			str[i++] = *str3++;
	str[size] = '\0';
	return (str);
}
