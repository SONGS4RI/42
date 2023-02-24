/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:12:02 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/24 15:22:50 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	b_to_a_reverse(t_stack *st_a, t_stack *st_b, int ra, int rb)
{
	if (st_b->size == rb)
		while (ra--)
			command_rr('a', st_a, st_b);
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

static void	b_to_a_func(t_stack *st_a, t_stack *st_b, int size, int arr[])
{
	int	pivot[2];

	pivot[0] = choose_pivot(st_b->top, size, size / 3, -1);
	pivot[1] = choose_pivot(st_b->top, size, (size * 2) / 3, -1);
	while (size--)
	{
		if (st_b->top->num >= pivot[0])
		{
			command_p('a', st_a, st_b);
			arr[0]++;
		}
		else if (st_b->top->num > pivot[1])
		{
			command_p('a', st_a, st_b);
			command_r('a', st_a, st_b);
			arr[1]++;
		}
		else
		{
			command_r('b', st_a, st_b);
			arr[2]++;
		}
	}
}

void	b_to_a(t_stack *st_a, t_stack *st_b, int size)
{
	int	arr[3];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	if (size <= 3)
	{
		st_under_three(st_a, st_b, st_b, size);
		return ;
	}
	b_to_a_func(st_a, st_b, size, arr);
	a_to_b(st_a, st_b, arr[0]);
	b_to_a_reverse(st_a, st_b, arr[1], arr[2]);
	a_to_b(st_a, st_b, arr[1]);
	b_to_a(st_a, st_b, arr[2]);
}
