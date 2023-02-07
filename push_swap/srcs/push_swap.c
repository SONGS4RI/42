/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:47:55 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/07 21:06:41 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	*split_to_int(char *s)
{
	
}

int	*init_a(char **argv)
{
	static int	idx;
	static int	len;
	char		*line;
	int			*res;

	while (argv[++idx])
		len += ft_strlen(argv[idx]) + 1;
	line = (char *)malloc(sizeof(char) * len);
	if (!line)
		return (NULL);
	idx = 0;
	len = -1;
	while (argv[++idx])
	{
		while (*argv[idx])
			line[++len] = *argv[idx]++;
		line[++len] = ' ';
	}
	line[len] = '\0';
	res = split_to_int(line);
	return (res);
}

int	main(int argc, char **argv)
{
	init_a(argv);
}
