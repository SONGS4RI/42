/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:48:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/19 14:47:51 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *st, int sorted)
{
	t_stack_node	*tmp;
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

	flag_a = is_sorted(st_a, st_a->sort);
	flag_b = is_sorted(st_b, st_b->sort);
	if (!flag_a && !flag_b)
		return (st_a);
	else if (!flag_a && flag_b)
		return (st_a);
	else if (flag_a && !flag_b)
		return (st_b);
	return (NULL);
}

void	check_switch_st_top(t_stack *st_a, t_stack *st_b, t_stack_node *pivot)
{
	int	flag_a;
	int	flag_b;

	flag_a = 0;
	flag_b = 0;
	if (st_a->size > 1 && st_a->top->next != pivot)
		if (st_a->top->num > st_a->top->next->num)
			flag_a = 1;
	if (st_b->size > 1 && st_b->top->next != pivot)
		if (st_b->top->num < st_b->top->next->num)
			flag_b = 1;
	if (flag_a && flag_b)
		command_s('s', st_a, st_b);
	else if(flag_a)
		command_s('a', st_a, st_b);
	else if(flag_b)
		command_s('b', st_a, st_b);
}

void	check_pivot_st(t_stack *st_a, t_stack *st_b, t_stack *pivot_st)
{
	check_switch_st_top(st_a, st_b, pivot_st->pivot);
	if (is_sorted(st_a, st_a->sort) && is_sorted(st_b, st_b->sort))
		return ;
	if (pivot_st == st_a)
	{
		if (pivot_st->top->num < pivot_st->pivot->num)
			command_p('b', st_a, st_b);
		else
			command_r('a', st_a, st_b);
	}
	else
	{
		if (pivot_st->top->num > pivot_st->pivot->num)
			command_p('a', st_a, st_b);
		else
			command_r('b', st_a, st_b);
	}
}

void	push_swap(t_stack *st_a, t_stack *st_b)
{
	t_stack	*pivot_st;

	while (1)
	{
		pivot_st = choose_pivot_stack(st_a, st_b);
		if (pivot_st)
			pivot_st->pivot = pivot_st->bottom;
		while (pivot_st && pivot_st->top != pivot_st->pivot)
		{
			check_pivot_st(st_a, st_b, pivot_st);
			if (is_sorted(pivot_st, pivot_st->sort))
				break ;
		}
		if (is_sorted(st_a, st_a->sort) && is_sorted(st_b, st_b->sort))
		{
			while (st_b->size)
			{
				command_p('a', st_a, st_b);
				check_switch_st_top(st_a, st_b, NULL);
			}
			break ;
		}
	}
}
