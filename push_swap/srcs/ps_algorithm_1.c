/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:48:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/20 20:17:40 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_to_b_reverse(t_stack *st_a, t_stack *st_b, int ra, int rb)
{
	if (st_a->size == ra)
		while (rb--)
			command_rr('b', st_a, st_b);
	else
	{
		while (ra || rb)
		{
			if (ra && rb)
			{
				command_rr('r', st_a, st_b);
				ra--;
				rb--;
			}
			else if (ra)
			{
				command_rr('a', st_a, st_b);
				ra--;
			}
			else if (rb)
			{
				command_rr('b', st_a, st_b);
				rb--;
			}
		}
	}
}

int	a_to_b_func(t_stack *st_a, t_stack *st_b, int size, int ra)
{
	int	pivot[2];
	int	rb;

	rb = 0;
	pivot[0] = choose_pivot(st_a->top, size, size / 3, -1);
	pivot[1] = choose_pivot(st_a->top, size, (size * 2) / 3, -1);
	while (size--)
	{
		if (st_a->top->num >= pivot[0])
		{
			command_r('a', st_a, st_b);
			ra++;
		}
		else if (st_a->top->num > pivot[1])
		{
			command_p('b', st_a, st_b);
			command_r('b', st_a, st_b);
			rb++;
		}
		else
			command_p('b', st_a, st_b);
	}
	a_to_b_reverse(st_a, st_b, ra, rb);
	return (ra);
}

void	a_to_b(t_stack *st_a, t_stack *st_b, int size)
{
	int	num;

	if (size <= 3)
	{
		st_under_three(st_a, st_b, st_a, size);
		return ;
	}
	if (is_sorted(st_a, size, 1))
		return ;
	num = a_to_b_func(st_a, st_b, size, 0);
	a_to_b(st_a, st_b, num);
	b_to_a(st_a, st_b, size - num);
}

int	b_to_a_func(t_stack *st_a, t_stack *st_b, int size, int rb)
{
	int	pivot[2];
	int	ra;

	ra = 0;
	pivot[0] = choose_pivot(st_b->top, size, size / 3, -1);
	pivot[1] = choose_pivot(st_b->top, size, (size * 2) / 3, -1);
	while (size--)
	{
		if (st_b->top->num >= pivot[0])
			command_p('a', st_a, st_b);
		else if (st_b->top->num > pivot[1])
		{
			command_p('a', st_a, st_b);
			command_r('a', st_a, st_b);
			ra++;
		}
		else
		{
			command_r('b', st_a, st_b);
			rb++;
		}
	}
	while (ra--)
		command_rr('a', st_a, st_b);
	return (rb);
}

void	b_to_a(t_stack *st_a, t_stack *st_b, int size)
{
	int	num;

	if (size <= 3)
	{
		st_under_three(st_a, st_b, st_b, size);
		return ;
	}
	num = b_to_a_func(st_a, st_b, size, 0);
	a_to_b(st_a, st_b, size - num);
	b_to_a(st_a, st_b, num);
}
