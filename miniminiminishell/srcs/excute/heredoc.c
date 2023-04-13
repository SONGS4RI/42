#include "../../includes/miniminiminishell.h"

static void	heredoc_handler(int signum)
{
	(void)signum;
	exit(1);
}

static char	*get_env_value_if(t_env_node *env_list, char *str, int *dollar_idx, int *next_idx)
{
	*next_idx = *dollar_idx + 1;
	if (str[*next_idx] == '?')
	{
		*next_idx += 1;
		return (ft_itoa(g_exit_status));
	}
	if (str[*next_idx] == '\0' || !ft_isalnum(str[*next_idx]))
		return (NULL);
	while (str[*next_idx] && (ft_isalnum(str[*next_idx]) || str[*next_idx] == '_'))
		*next_idx += 1;
	return (free_env_key_and_get_env_value(env_list, \
	ft_substr(str, *dollar_idx + 1, *next_idx - *dollar_idx - 1)));
}

void	handle_heredoc_env(t_env_node *env_list, int fd, char *str)
{
	int		start_idx;
	int		end_idx;
	char	*env_value;

	start_idx = 0;
	end_idx = 0;
	while (str[end_idx])
	{
		if (str[end_idx] == '$')
		{	
			write(fd, str + start_idx, end_idx - start_idx);
			start_idx = end_idx;
			env_value = get_env_value_if(env_list, str, &start_idx, &end_idx);
			if (env_value)
			{
				write(fd, env_value, ft_strlen(env_value));
				start_idx = end_idx;
				free(env_value);
			}
		}
		else
			end_idx++;
	}
	write(fd, str + start_idx, end_idx - start_idx);
}

int	ms_heredoc(t_env_node *env_list, char *limiter)
{
	int		fd;
	char	*input;

	fd = open("heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	while (1)
	{
		signal(SIGINT, heredoc_handler);
		input = readline("> ");
		signal(SIGINT, child_handler);
		if (input == NULL || (ft_strlen(input) == ft_strlen(limiter) \
		&& ft_strncmp(input, limiter, ft_strlen(input)) == 0))
			break ;
		handle_heredoc_env(env_list, fd, input);
		write(fd, "\n", 1);
		free(input);
		
	}
	close(fd);
	free(input);
	return (open("heredoc.tmp", O_RDONLY));
}
