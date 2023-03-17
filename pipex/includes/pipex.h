/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:47:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/17 17:07:14 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	**argv;
	char	**envp;
	char	**path;
	char	**cmd_arg1;
	char	**cmd_arg2;
	char	*cmd1;
	char	*cmd2;
	int		pipe_fd[2];
	pid_t	pid;
}	t_arg;

void	parse_to_arg(t_arg *arg);

void	free_arg(char **s);
void	exit_err(t_arg *arg, char *str, char *err_msg, int status);
void	init_arg(t_arg *arg);

#endif