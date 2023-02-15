/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:48:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/15 20:33:39 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compare_num(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

int	is_sorted(t_stack *st)
{
	t_stack_node 	*tmp;
	static int		sorted = 1;

	if (st->size > 1)
	{
		tmp = st->top;
		sorted = compare_num(tmp->num, tmp->next->num);
		while (tmp->next && sorted)
		{
			if (sorted != compare_num(tmp->num, tmp->next->num))
				sorted = 0;
			tmp = tmp->next;
		}
	}
	return (sorted);
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

void	check_stacks(t_stack *st_a, t_stack *st_b)
{
	
}