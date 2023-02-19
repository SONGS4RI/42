/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:18:47 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/16 22:31:43 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare_num(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	free_ps_stack(t_stack *st)
{
	t_stack_node	*node;
	t_stack_node	*tmp;

	node = st->top;
	while (node)
	{
		tmp = node->next;
		node->previous = NULL;
		free(node);
		node = tmp;
	}
	free(st);
	st = NULL;
}

void	err_exit(t_stack *st, char *line, char *err_msg)
{
	write(2, "Error\n", 6);
	write(2, err_msg, ft_strlen(err_msg));
	if (line)
		free(line);
	if (st)
		free_ps_stack(st);
	exit(1);
}
