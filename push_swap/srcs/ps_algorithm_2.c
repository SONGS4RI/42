/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:48:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/20 17:24:03 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_ascending(t_stack *st_a, t_stack *st_b, int b, int c)
{
	int	a;

	a = st_a->top->num;
	if ((a < b && a < c && b > c) || (a > b && a > c && b < c))
	{
		if (a > b && a > c && b < c)
			command_s('a', st_a, st_b);
		command_r('a', st_a, st_b, NULL);
		command_s('a', st_a, st_b);
		command_rr('a', st_a, st_b);
	}
	else if (a > b && a < c && b < c)
		command_s('a', st_a, st_b);
	else if ((a < b && a > c && b > c) || (a > b && a > c && b > c))
	{
		if (a > b && a > c && b > c)
			command_s('a', st_a, st_b);
		command_r('a', st_a, st_b, NULL);
		command_s('a', st_a, st_b);
		command_rr('a', st_a, st_b);
		command_s('a', st_a, st_b);
	}
}

void	sort_three_descending(t_stack *st_a, t_stack *st_b, int b, int c)
{
	int	a;

	a = st_a->top->num;
	if ((a < b && a < c && b > c) || (a < b && a > c && b > c) || \
	(a > b && a > c && b < c) || (a > b && a > c && b > c))
	{
		if ((a < b && a < c && b > c) || (a < b && a > c && b > c))
			command_s('b', st_a, st_b);
		command_p('a', st_a, st_b);
		command_p('a', st_a, st_b);
		command_p('a', st_a, st_b);
		if ((a < b && a < c && b > c) || (a > b && a > c && b < c))
			command_s('b', st_a, st_b);
	}
	else if ((a > b && a < c && b < c) || (a < b && a < c && b < c))
	{
		if (a < b && a < c && b < c)
			command_s('b', st_a, st_b);
		command_p('a', st_a, st_b);
		command_s('b', st_a, st_b);
		command_p('a', st_a, st_b);
		command_s('a', st_a, st_b);
		command_p('a', st_a, st_b);
	}
}

void	st_under_three(t_stack *st_a, t_stack *st_b, t_stack *tmp, int size)
{
	if (tmp == st_a)
	{
		if (size == 2 && !is_sorted(st_a, 2, 1))
			command_r('a', st_a, st_b, NULL);
		else if (size == 3 && !is_sorted(st_a, 3, 1))
			sort_three_ascending(st_a, st_b, st_a->top->next->num, \
			st_a->top->next->next->num);
	}
	else
	{
		if (size == 1)
			command_p('a', st_a, st_b);
		else if (size == 2)
		{
			if (!is_sorted(st_a, 2, -1))
				command_r('b', st_a, st_b, NULL);
			command_p('a', st_a, st_b);
			command_p('a', st_a, st_b);
		}
		else if (size == 3 && !is_sorted(st_a, 3, -1))
			sort_three_descending(st_a, st_b, st_b->top->next->num, \
			st_b->top->next->next->num);
	}
}
