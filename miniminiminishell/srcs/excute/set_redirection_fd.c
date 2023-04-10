#include "../../includes/miniminiminishell.h"

static int	get_infile_fd(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1 || dup2(fd, STDIN_FILENO) == -1)
	{
		ms_error(infile, NULL);
		return (-1);
	}
	// return (fd);
	close(fd);
	return (0);
}

void	heredoc_handler(int signum)
{
	(void)signum;
	exit(1);
}

static int	ms_heredoc(char *limiter)
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
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
		input = NULL;////////////////////
	}
	close(fd);
	free(input);
	return (open("heredoc.tmp", O_RDONLY));
}

static int	get_heredoc_fd(char *limiter)
{
	int	fd;
	fd = ms_heredoc(limiter);
	if (fd == -1 || dup2(fd, STDIN_FILENO) == -1)
	{
		ms_error("heredoc", NULL);
		return (-1);
	}
	// return (fd);
	close(fd);
	return (0);
}

static int	get_overwrite_fd(char *outfile)
{
	int	fd;
	
	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1 || dup2(fd, STDOUT_FILENO) == -1)
	{
		ms_error(outfile, NULL);
		return (-1);
	}
	// return (fd);
	close(fd);
	return (0);
}

static int	get_append_fd(char *outfile)
{
	int	fd;
	
	fd = open(outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1 || dup2(fd, STDOUT_FILENO) == -1)
	{
		ms_error(outfile, NULL);
		return (-1);
	}
	// return (fd);
	close(fd);
	return (0);
}

int	set_redirection_fd(t_cmd *cmd_list)
{
	int				result;
	t_redirection	*cur;

	cur = cmd_list->redirection;
	while (cur)
	{
		if (ft_strncmp(cur->type, "<<", 2) == 0)
			result = get_heredoc_fd(cur->file);
		else if (ft_strncmp(cur->type, "<", 1) == 0)
			result = get_infile_fd(cur->file);
		else if (ft_strncmp(cur->type, ">>", 2) == 0)
			result = get_append_fd(cur->file);
		else if (ft_strncmp(cur->type, ">", 1) == 0)
			result = get_overwrite_fd(cur->file);
		if (result == -1)
			return (-1);
		cur = cur->next;
	}
	return (0);
}
