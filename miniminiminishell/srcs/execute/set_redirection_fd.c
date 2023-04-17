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

static int	get_heredoc_fd(t_info *info, char *limiter)
{
	int	fd;
	int	temp;

	temp = dup(STDOUT_FILENO);
	dup2(info->stdin, STDIN_FILENO);
	dup2(info->stdout, STDOUT_FILENO);
	fd = ms_heredoc(info->env_list, limiter);
	dup2(temp, STDOUT_FILENO);
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

int	set_redirection_fd(t_info *info, t_cmd *cmd_list)
{
	int				result;
	t_redirection	*cur;

	cur = cmd_list->redirection;
	while (cur)
	{
		if (ft_strncmp(cur->type, "<<", 2) == 0)
			result = get_heredoc_fd(info, cur->file);
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
