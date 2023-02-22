/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_a_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:11:22 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/22 17:40:21 by jahlee           ###   ########.fr       */
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

void	a_to_b_func(t_stack *st_a, t_stack *st_b, int size, int arr[])
{
	int	pivot[2];

	pivot[0] = choose_pivot(st_a->top, size, size / 3, -1);
	pivot[1] = choose_pivot(st_a->top, size, (size * 2) / 3, -1);
	// printf("pivot: %d %d\n",pivot[1],pivot[0]);///////////////////////////////////////
	while (size--)
	{
		if (st_a->top->num >= pivot[0])
		{
			command_r('a', st_a, st_b);
			arr[0]++;
		}
		else if (st_a->top->num > pivot[1])
		{
			command_p('b', st_a, st_b);
			command_r('b', st_a, st_b);
			arr[1]++;
		}
		else
		{
			command_p('b', st_a, st_b);
			arr[2]++;
		}
	}
	a_to_b_reverse(st_a, st_b, arr[0], arr[1]);
}

void	a_to_b(t_stack *st_a, t_stack *st_b, int size)
{
	int	arr[3];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	// printf("====================a_to_b(%d)===================\n",size);///////////////////
	// print_cur(st_a, st_b);///////////////////////////////////////////////////////
	if (size <= 3)
	{
		st_under_three(st_a, st_b, st_a, size);
		return ;
	}
	if (is_sorted(st_a, size, 1))
		return ;
	a_to_b_func(st_a, st_b, size, arr);
	a_to_b(st_a, st_b, arr[0]);
	b_to_a(st_a, st_b, arr[1]);
	b_to_a(st_a, st_b, arr[2]);
}
