/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:47:55 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/20 20:37:20 by jahlee           ###   ########.fr       */
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
	(*st_a)->size = 0;
	*st_b = (t_stack *)malloc(sizeof(t_stack));
	if (!st_b)
		err_exit(*st_a, NULL, "malloc err : st_b\n");
	(*st_b)->top = NULL;
	(*st_b)->bottom = NULL;
	(*st_b)->size = 0;
}

void	invalid_check(t_stack *st, t_stack_node	*node, int sorted)
{
	t_stack_node	*tmp;

	if (!st->size)
		err_exit(st, NULL, "no parameter\n");
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
			printf("%d", a_tmp->num);
			a_tmp = a_tmp->next;
		}
		printf("	");
		if (b_tmp)
		{
			printf("%d", b_tmp->num);
			b_tmp = b_tmp->next;
		}
		printf("\n");
	}
	printf("-	-\n");
	printf("a	b\n");
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	// atexit(leaks);////////////////////
	init_stack(&st_a, &st_b);
	argv_to_stack(argv, &st_a);
	invalid_check(st_a, st_a->top, 1);
	a_to_b(st_a, st_b, st_a->size);
	// printf("========result==========\n");//////////////////
	// print_cur(st_a, st_b);///////////////////
	return (0);
}
