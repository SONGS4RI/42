/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:47:55 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/10 13:10:51 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_a(char **argv, t_stack *st)
{
	static int	idx;
	static int	len;
	char		*line;

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
	return (split_to_stack(line, st));
}

int	main(int argc, char **argv)
{
	t_stack	*st;

	st = NULL;
	st = init_a(argv, st);
}
