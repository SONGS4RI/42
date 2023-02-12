/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:39:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/12 20:00:26 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*popfront(t_stack **st)
{
	t_stack_node	*node;

	node = (*st)->top;
	(*st)->top = (*st)->top->next;
	(*st)->top->prevoius = NULL;
	return (node);
}

t_stack_node	*popback(t_stack **st)
{
	t_stack_node	*node;

	node = (*st)->bottom;
	(*st)->bottom = (*st)->bottom->prevoius;
	(*st)->bottom->next = NULL;
	return (node);
}

void	pushfront(t_stack_node *node, t_stack **to)
{
	node->next = (*to)->top;
	node->prevoius = NULL;
	(*to)->top->prevoius = node;
	(*to)->top = node;
}

void	pushback(t_stack_node *node, t_stack **to)
{
	node->next = NULL;
	node->prevoius = (*to)->bottom;
	(*to)->bottom->next = node;
	(*to)->bottom = node;
}
