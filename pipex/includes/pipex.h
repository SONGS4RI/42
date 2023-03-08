/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:47:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/08 15:55:14 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>//open, close
# include <string.h>//perror, strerror
# include <string.h>//strerror
# include <stdio.h>//perror
# include <sys/wait.h>// wait, waitpid

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	**envp;
	char	**path;
	char	**cmd_arg1;
	char	**cmd_arg2;
	char	*cmd1;
	char	*cmd2;
	int		pipe_fd[2];
	pid_t	pid;
	pid_t	pid_child;
	int		status;
}	t_arg;

void	exit_err(t_arg *arg, char *str);
char	**get_path_envp(char **envp);
char	*get_cmd_argv(char **path, char *cmd);
void	parse_to_arg(t_arg *arg, char **argv, char **envp);

#endif