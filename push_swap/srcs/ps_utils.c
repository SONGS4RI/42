/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:18:47 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/12 18:01:15 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_ps_stack(t_stack *st)
{
	t_stack_node	*node;
	t_stack_node	*tmp;

	node = st->top;
	while (node)
	{
		tmp = node->next;
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
