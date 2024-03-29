/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:39:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/14 15:15:23 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*popfront(t_stack *st)
{
	t_stack_node	*node;

	node = NULL;
	if (st->size)
	{
		node = st->top;
		st->top = st->top->next;
		if (!st->top)
			st->bottom = NULL;
		else
			st->top->previous = NULL;
		st->size--;
	}
	return (node);
}

t_stack_node	*popback(t_stack *st)
{
	t_stack_node	*node;

	node = NULL;
	if (st->size)
	{
		node = st->bottom;
		st->bottom = st->bottom->previous;
		if (!st->bottom)
			st->top = NULL;
		else
			st->bottom->next = NULL;
		st->size--;
	}
	return (node);
}

void	pushfront(t_stack_node *node, t_stack *to)
{
	if (node)
	{
		node->next = to->top;
		node->previous = NULL;
		if (!to->size)
			to->bottom = node;
		else
			to->top->previous = node;
		to->top = node;
		to->size++;
	}
}

void	pushback(t_stack_node *node, t_stack *to)
{
	if (node)
	{
		node->next = NULL;
		node->previous = to->bottom;
		if (!to->size)
			to->top = node;
		else
			to->bottom->next = node;
		to->bottom = node;
		to->size++;
	}
}
