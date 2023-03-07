/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:38:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/06 17:40:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_arg(char **s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
}

void	exit_err(t_arg *arg, char *str)
{
	write(2, str, ft_strlen(str));
	free_arg(arg->cmd1);
	free_arg(arg->cmd2);
	free_arg(arg->path);
	exit(1);
}

void	init_arg(t_arg *arg)
{
	arg->path = NULL;
	arg->cmd1 = NULL;
	arg->cmd2 = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	init_arg(&arg);
	if (argc != 5)
		exit_err(NULL, "Wrong Usage: ./pipex file1 cmd1 cmd2 file2\n");
	arg.infile = open(argv[1], O_RDONLY);
	if (arg.infile == -1)
		exit_err(NULL, "infile open error\n");
	arg.outfile = open(argv[4], O_WRONLY);
	if (arg.outfile == -1)
		exit_err(NULL, "outfile open error\n");
	arg.path = get_path_envp(envp);// 환경변수에서 PATH 를 찾아서 PATH= 이후의 글자를 :로 나눠서 저장
	arg.cmd1 = ft_split(argv[2], ' ');
	arg.cmd2 = ft_split(argv[3], ' ');
	if (!arg.outfile || !arg.cmd1 || !arg.cmd2)
		exit_err(&arg, "argv split error\n");
	close(arg.infile);
	close(arg.infile);
	return (0);
}
