#include "../../includes/miniminiminishell.h"

static void	signal_handler(int signum)
{
	if (signum == SIGINT)
		printf("🍄 minishell$ \n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	set_signal(void)
{
	signal(SIGINT, signal_handler);	// ctrl + C
	signal(SIGQUIT, SIG_IGN);		// ctrl + "\"
}

void	free_2d_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
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
	while (*str1)
		str[i++] = *str1++;
	while (*str2)
		str[i++] = *str2++;
	while (*str3)
		str[i++] = *str3++;
	str[size] = '\0';
	return (str);
}
