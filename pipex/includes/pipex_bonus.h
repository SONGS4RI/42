/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:47:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/15 20:05:14 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/includes/libft.h"
# include <fcntl.h>//open, close
# include <string.h>//strerror
# include <stdio.h>//perror
# include <sys/wait.h>// wait, waitpid
# include <errno.h>//errno

typedef struct s_arg
{
	int		infile;
	int		outfile;
	int		argc;
	int		cmd_cnt;
	int		here_doc;
	int		pipe_even[2];
	int		pipe_odd[2];
	char	**argv;
	char	**envp;
	char	**path;
	char	**cmd;
	char	***cmd_arg;
	pid_t	pid;
}	t_arg;

void	child_work(t_arg *arg, int i);
void	parent_work(t_arg *arg);

char	**get_path_envp(char **envp);
char	*get_cmd_argv(char **path, char *cmd);
void	parse_to_arg(t_arg *arg);

void	free_arg(char **s);
void	exit_err(t_arg *arg, char *str, char *err_msg, int status);
void	init_arg(t_arg *arg, int argc, char **argv, char **envp);

void	heredoc(t_arg *arg, char *s, char *tag);
void	set_infile_fd(t_arg *arg);
void	set_outfile_fd(t_arg *arg);

#endif