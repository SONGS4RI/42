/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:18:47 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/23 15:26:40 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	compare_num(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

int	is_sorted(t_stack *st, int size, int sorted)
{
	t_stack_node	*tmp;
	int				compare;

	if (size > 1)
	{
		tmp = st->top;
		while (tmp->next && --size)
		{
			if (sorted != compare_num(tmp->num, tmp->next->num))
				return (0);
			tmp = tmp->next;
		}
	}
	return (sorted);
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
		node->next = NULL;
		free(node);
		node = tmp;
	}
	free(st);
	st = NULL;
}

void	err_exit(t_stack *st, char *line)
{
	write(2, "Error\n", 6);
	if (line)
		free(line);
	if (st)
		free_ps_stack(st);
	exit(1);
}
