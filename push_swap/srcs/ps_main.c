/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:47:55 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/16 23:46:06 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	argv_to_stack(char **argv, t_stack **st)
{
	static int	idx;
	static int	len;
	char		*line;

	while (argv[++idx])
		len += ft_strlen(argv[idx]) + 1;
	line = (char *)malloc(sizeof(char) * len);
	if (!line)
		return ;
	idx = 0;
	len = -1;
	while (argv[++idx])
	{
		while (*argv[idx])
			line[++len] = *argv[idx]++;
		line[++len] = ' ';
	}
	line[len] = '\0';
	split_to_stack(line, st);
}

void	init_stack(t_stack **st_a, t_stack **st_b)
{
	*st_a = (t_stack *)malloc(sizeof(t_stack));
	if (!st_a)
		err_exit(NULL, NULL, "malloc err : st_a\n");
	(*st_a)->top = NULL;
	(*st_a)->bottom = NULL;
	(*st_a)->pivot = NULL;
	(*st_a)->size = 0;
	(*st_a)->sort = 1;
	*st_b = (t_stack *)malloc(sizeof(t_stack));
	if (!st_b)
		err_exit(*st_a, NULL, "malloc err : st_b\n");
	(*st_b)->top = NULL;
	(*st_b)->bottom = NULL;
	(*st_b)->pivot = NULL;
	(*st_b)->size = 0;
	(*st_b)->sort = -1;
}

void	invalid_check(t_stack *st, t_stack_node	*node, int sorted)
{
	t_stack_node	*tmp;

	while (node)
	{
		tmp = node->next;
		while (tmp)
		{
			if (node->num == tmp->num)
				err_exit(st, NULL, "duplicated\n");
			tmp = tmp->next;
		}
		if (node->next && node->num > node->next->num)
			sorted = 0;
		node = node->next;
	}
	if (sorted)
	{
		free_ps_stack(st);
		exit(0);
	}
}

void	leaks(void)////////////////////
{
	system("leaks push_swap");
}

void	print_cur(t_stack *a, t_stack *b)/////////////////////////
{
	t_stack_node	*a_tmp;
	t_stack_node	*b_tmp;

	a_tmp = a->top;
	b_tmp = b->top;
	while (a_tmp || b_tmp)
	{
		if (a_tmp)
		{
			printf("%d	", a_tmp->num);
			a_tmp = a_tmp->next;
		}
		if (b_tmp)
		{
			printf("%d", b_tmp->num);
			b_tmp = b_tmp->next;
		}
		printf("\n");
	}
	printf("-	-\n");
	printf("a%d	b%d\n", a->size, b->size);
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	// atexit(leaks);////////////////////
	if (argc == 1)
		err_exit(NULL, NULL, "Wrong Usage\n");
	init_stack(&st_a, &st_b);
	argv_to_stack(argv, &st_a);
	invalid_check(st_a, st_a->top, 1);
	print_cur(st_a,st_b);////////////
	if (is_sorted(st_a, -1) && st_a->size > 3)
	{
		command_rr('a', st_a, st_b);
		command_s('a', st_a, st_b);
		command_r('a', st_a, st_b);
	}
	push_swap(st_a, st_b);
	print_cur(st_a,st_b);////////////
	return (0);
}
/*
4 5 3 2 1 => 13개
*/