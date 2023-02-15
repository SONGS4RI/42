/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:48:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/15 21:02:03 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare_num(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

int	is_sorted(t_stack *st, int sorted)
{
	t_stack_node 	*tmp;
	int				compare;

	if (st->size > 1)
	{
		tmp = st->top;
		compare = compare_num(tmp->num, tmp->next->num);
		if (compare != sorted)
			return (0);
		while (tmp->next)
		{
			if (sorted != compare_num(tmp->num, tmp->next->num))
				return (0);
			tmp = tmp->next;
		}
	}
	return (sorted);
}

t_stack	*choose_pivot_stack(t_stack *st_a, t_stack *st_b)
{
	int	flag_a;
	int	flag_b;

	flag_a = is_sorted(st_a, 1);
	flag_b = is_sorted(st_b, -1);
	if (!flag_a && !flag_b)
		return (st_a);
	else if (!flag_a && flag_b == -1)
		return (st_a);
	return (st_b);
}

void	check_switch_st_top(t_stack *st_a, t_stack *st_b, int pivot)
{
	static int	flag_a = 0;
	static int	flag_b = 0;

	if (st_a->size > 1 && st_a->top->next->num != pivot)
		if (st_a->top->num > st_a->top->next->num)
			flag_a = 1;
	if (st_b->size > 1 && st_b->top->next->num != pivot)
		if (st_b->top->num < st_b->top->next->num)
			flag_b = 1;
	if (flag_a && flag_b)
		command_s("s", st_a, st_b);
	else if(flag_a)
		command_s("a", st_a, st_b);
	else if(flag_b)
		command_s("b", st_a, st_b);
}

void	push_swap(t_stack *st_a, t_stack *st_b)
{
	t_stack	*pivot_st;

	while (1)
	{
		pivot_st = choose_pivot_stack(st_a, st_b);
		while (1)
		{
			
		}
		if (st_a->sort == 1 && st_b->sort == -1)
		{
			while (st_b->size)
			{
				command_p('a', st_a, st_b);
				check_switch_st_top(st_a, st_b, st_a->bottom->num);
			}
			break ;
		}
	}
}