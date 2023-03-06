/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:38:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/06 17:11:26 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_err(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	if (argc != 5)
		exit_err("Wrong Usage: ./pipex file1 cmd1 cmd2 file2\n");
	/*
		argv[1] 	: infile
		argv[2 ~ 3] : cmd
		argv[4]		: outfile
	*/
	/*
		존재하는 cmd인지 확인
		infile을 표준입력으로 설정
		cmd한 결과를 outfile에 저장
	*/
	arg.infile = open(argv[1], O_RDONLY);
	if (arg.infile == -1)
		exit_err("infile open error\n");
	arg.outfile = open(argv[4], O_WRONLY);
	if (arg.outfile == -1)
		exit_err("outfile open error\n");
	// 환경변수에서 PATH 를 찾아서 PATH= 이후의 글자를 :로 나눠서 저장
	arg.path = get_path_envp(envp);
	close(arg.infile);
	close(arg.infile);
	return (0);
}
