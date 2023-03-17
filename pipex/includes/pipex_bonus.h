/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:47:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/17 16:55:28 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_arg
{
	int		infile;
	int		outfile;
	int		argc;
	int		cmd_cnt;
	int		here_doc;
	int		init_err;
	int		pipe_even[2];
	int		pipe_odd[2];
	char	**argv;
	char	**envp;
	char	**path;
	char	**cmd;
	char	***cmd_arg;
	pid_t	pid;
}	t_arg;

void	parse_to_arg(t_arg *arg);

void	set_infile_fd(t_arg *arg);
void	set_outfile_fd(t_arg *arg);

void	free_arg(char **s);
void	exit_err(t_arg *arg, char *str, int status);
void	init_arg(t_arg *arg, int argc, char **argv, char **envp);
#endif