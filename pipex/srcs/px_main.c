/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:38:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/03 19:59:56 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_err(char *str)
{
	write(2, str, );
	exit(1);
}

int	main(int argc, char **envp)
{
	if (argc != 5)
		return (exit_err("Wrong Usage: ./pipex file1 cmd1 cmd2 file2\n"));
	return (0);
}
