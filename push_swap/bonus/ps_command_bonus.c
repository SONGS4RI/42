/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:03:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/22 20:20:33 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	command_s(char c, t_stack *st_a, t_stack *st_b)
{
	t_stack_node	*tmp1;
	t_stack_node	*tmp2;

	if ((c == 'a' && st_a->size > 1) || (c == 'b' && st_b->size > 1) || \
	(c == 's' && (st_a->size > 1 || st_b->size > 1)))
	{
		if (c == 'a' || c == 's')
		{
			tmp1 = popfront(st_a);
			tmp2 = popfront(st_a);
			pushfront(tmp1, st_a);
			pushfront(tmp2, st_a);
		}
		if (c == 'b' || c == 's')
		{
			tmp1 = popfront(st_b);
			tmp2 = popfront(st_b);
			pushfront(tmp1, st_b);
			pushfront(tmp2, st_b);
		}
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	command_p(char c, t_stack *st_a, t_stack *st_b)
{
	if ((c == 'a' && st_b->size) || (c == 'b' && st_a->size))
	{
		if (c == 'a')
			pushfront(popfront(st_b), st_a);
		else if (c == 'b')
			pushfront(popfront(st_a), st_b);
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	command_r(char c, t_stack *st_a, t_stack *st_b)
{
	if ((c == 'a' && st_a->size > 1) || (c == 'b' && st_b->size > 1) || \
	(c == 'r' && (st_a->size > 1 || st_b->size > 1)))
	{
		if (c == 'a' || c == 'r')
			pushback(popfront(st_a), st_a);
		if (c == 'b' || c == 'r')
			pushback(popfront(st_b), st_b);
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	command_rr(char c, t_stack *st_a, t_stack *st_b)
{
	if ((c == 'a' && st_a->size > 1) || (c == 'b' && st_b->size > 1) || \
	(c == 'r' && (st_a->size > 1 || st_b->size > 1)))
	{
		if (c == 'a' || c == 'r')
			pushfront(popback(st_a), st_a);
		if (c == 'b' || c == 'r')
			pushfront(popback(st_b), st_b);
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
