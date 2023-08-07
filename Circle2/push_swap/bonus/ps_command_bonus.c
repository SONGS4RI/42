/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:03:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/23 19:14:34 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
	}
}

void	do_command(t_stack *st_a, t_stack *st_b, char *str)
{
	if (!ft_strncmp("sa\n", str, ft_strlen(str)))
		command_s('a', st_a, st_b);
	else if (!ft_strncmp("sb\n", str, ft_strlen(str)))
		command_s('b', st_a, st_b);
	else if (!ft_strncmp("ss\n", str, ft_strlen(str)))
		command_s('s', st_a, st_b);
	else if (!ft_strncmp("pa\n", str, ft_strlen(str)))
		command_p('a', st_a, st_b);
	else if (!ft_strncmp("pb\n", str, ft_strlen(str)))
		command_p('b', st_a, st_b);
	else if (!ft_strncmp("ra\n", str, ft_strlen(str)))
		command_r('a', st_a, st_b);
	else if (!ft_strncmp("rb\n", str, ft_strlen(str)))
		command_r('b', st_a, st_b);
	else if (!ft_strncmp("rr\n", str, ft_strlen(str)))
		command_r('r', st_a, st_b);
	else if (!ft_strncmp("rra\n", str, ft_strlen(str)))
		command_rr('a', st_a, st_b);
	else if (!ft_strncmp("rrb\n", str, ft_strlen(str)))
		command_rr('b', st_a, st_b);
	else if (!ft_strncmp("rrr\n", str, ft_strlen(str)))
		command_rr('r', st_a, st_b);
	else
		err_exit(st_a, st_b, NULL);
}
