/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:48:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/23 15:11:01 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	choose_pivot(t_stack_node *node, int size, int point, int i)
{
	int				j;
	int				cnt;
	t_stack_node	*tmp;
	t_stack_node	*cmp;

	while (++i < size)
	{
		tmp = node;
		cmp = node;
		cnt = 0;
		j = -1;
		while (++j < i)
			tmp = tmp->next;
		j = -1;
		while (++j < size && cnt <= point)
		{
			if (tmp->num < cmp->num)
				cnt++;
			cmp = cmp->next;
		}
		if (cnt == point)
			break ;
	}
	return (tmp->num);
}

void	sort_three_ascending(t_stack *st_a, t_stack *st_b, int b, int c)
{
	int	a;

	a = st_a->top->num;
	if (st_a->size == 3)
		size_three_ascending(st_a, st_b, st_a->top->next->num, \
			st_a->top->next->next->num);
	else if ((a < b && a < c && b > c) || (a > b && a > c && b < c))
	{
		if (a > b && a > c && b < c)
			command_s('a', st_a, st_b);
		command_r('a', st_a, st_b);
		command_s('a', st_a, st_b);
		command_rr('a', st_a, st_b);
	}
	else if (a > b && a < c && b < c)
		command_s('a', st_a, st_b);
	else if ((a < b && a > c && b > c) || (a > b && a > c && b > c))
	{
		if (a > b && a > c && b > c)
			command_s('a', st_a, st_b);
		command_r('a', st_a, st_b);
		command_s('a', st_a, st_b);
		command_rr('a', st_a, st_b);
		command_s('a', st_a, st_b);
	}
}

void	sort_three_descending(t_stack *st_a, t_stack *st_b, int b, int c)
{
	int	a;

	a = st_b->top->num;
	if ((a < b && a < c && b > c) || (a < b && a > c && b > c) || \
	(a > b && a > c && b < c) || (a > b && a > c && b > c))
	{
		if ((a < b && a < c && b > c) || (a < b && a > c && b > c))
			command_s('b', st_a, st_b);
		command_p('a', st_a, st_b);
		command_p('a', st_a, st_b);
		command_p('a', st_a, st_b);
		if ((a < b && a < c && b > c) || (a > b && a > c && b < c))
			command_s('a', st_a, st_b);
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

void	size_three_ascending(t_stack *st_a, t_stack *st_b, int b, int c)
{
	int	a;

	a = st_a->top->num;
	if ((a < b && a < c && b > c))
	{
		command_rr('a', st_a, st_b);
		command_s('a', st_a, st_b);
	}
	else if ((a < b && a > c && b > c))
		command_rr('a', st_a, st_b);
	else if ((a > b && a > c && b < c))
		command_r('a', st_a, st_b);
	else if ((a > b && a > c && b > c))
	{
		command_s('a', st_a, st_b);
		command_rr('a', st_a, st_b);
	}
	else if ((a > b && a < c && b < c))
		command_s('a', st_a, st_b);
}

void	st_under_three(t_stack *st_a, t_stack *st_b, t_stack *tmp, int size)
{
	if (tmp == st_a)
	{
		if (size == 2 && !is_sorted(st_a, 2, 1))
			command_s('a', st_a, st_b);
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
			if (!is_sorted(st_b, 2, -1))
				command_s('b', st_a, st_b);
			command_p('a', st_a, st_b);
			command_p('a', st_a, st_b);
		}
		else if (size == 3)
			sort_three_descending(st_a, st_b, st_b->top->next->num, \
			st_b->top->next->next->num);
	}
}
