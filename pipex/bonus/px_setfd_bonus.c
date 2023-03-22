/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_setfd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:48:33 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/22 15:41:58 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	heredoc(t_arg *arg, char *s, char *tag)
{
	unlink(arg->argv[1]);
	arg->infile = open(arg->argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (arg->infile < 0)
	{
		arg->here_doc = -1;
		return ;
	}
	while (1)
	{
		s = get_next_line(0);
		if (!s || !ft_strncmp(s, tag, ft_strlen(s)))
		{
			free(s);
			free(tag);
			break ;
		}
		write(arg->infile, s, ft_strlen(s));
		free(s);
	}
	close(arg->infile);
}

void	set_infile_fd(t_arg *arg)
{
	if (arg->here_doc)
		heredoc(arg, NULL, ft_strjoin(arg->argv[2], "\n"));
	arg->infile = open(arg->argv[1], O_RDONLY);
	if (arg->infile < 0)
	{
		perror(arg->argv[1]);
		arg->infile = open("void_file", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	if (dup2(arg->infile, STDIN_FILENO) == -1)
		exit_err(arg, "dup2 error", 1);
}

void	set_outfile_fd(t_arg *arg)
{
	int	idx;

	idx = arg->argc - 1;
	unlink("void_file");
	if (arg->here_doc)
	{
		unlink(arg->argv[1]);
		arg->outfile = open(arg->argv[idx], O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else
		arg->outfile = open(arg->argv[idx], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->outfile < 0)
		exit_err(arg, arg->argv[idx], 1);
	if (dup2(arg->outfile, STDOUT_FILENO) == -1)
		exit_err(arg, "dup2 error", 1);
	close(arg->outfile);
}
