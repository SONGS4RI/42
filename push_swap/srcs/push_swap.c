/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:47:55 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/12 19:32:51 by jahlee           ###   ########.fr       */
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

void	invalid_check(t_stack *st)
{
	t_stack_node	*node;
	t_stack_node	*tmp;
	static int		err = 1;

	node = st->top;
	while (node)
	{
		tmp = node->next;
		while (tmp)
		{
			if (node->num == tmp->num)
				err_exit(st, NULL, "duplicated\n");
			tmp = tmp->next;
		}
		if (st->size != 1 && node->next && node->num > node->next->num)
			err = 0;
		node = node->next;
	}
	if (err)
		err_exit(st, NULL, "already sorted\n");
}

void	leaks(void)////////////////////
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	atexit(leaks);////////////////////
	if (argc == 1)
		err_exit(NULL, NULL, "Wrong Usage\n");
	init_stack(&st_a, &st_b);
	argv_to_stack(argv, &st_a);
	invalid_check(st_a);
	printf("stack size : %d\n",st_a->size);//////////////////
	while (st_a->top)//////////////////////////////////////
	{
		printf("|%d|\n", st_a->top->num);
		st_a->top = st_a->top->next;
	}
	return (0);
}
