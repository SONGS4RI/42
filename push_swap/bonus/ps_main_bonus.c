/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:47:55 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/24 15:23:43 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	argv_to_stack(char **argv, t_stack *st)
{
	static int	idx;
	static int	len;
	char		*line;

	while (argv[++idx])
	{
		if (argv[idx][0] == '\0')
			err_exit(st, NULL, NULL);
		len += ft_strlen(argv[idx]) + 1;
	}
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

static void	init_stack(t_stack **st_a, t_stack **st_b)
{
	*st_a = (t_stack *)malloc(sizeof(t_stack));
	if (!st_a)
		err_exit(NULL, NULL, NULL);
	(*st_a)->top = NULL;
	(*st_a)->bottom = NULL;
	(*st_a)->size = 0;
	*st_b = (t_stack *)malloc(sizeof(t_stack));
	if (!st_b)
		err_exit(*st_a, NULL, NULL);
	(*st_b)->top = NULL;
	(*st_b)->bottom = NULL;
	(*st_b)->size = 0;
}

static void	invalid_check(t_stack *st, t_stack_node	*node, int sorted)
{
	t_stack_node	*tmp;

	if (!st->size)
	{
		free_ps_stack(st);
		exit(0);
	}
	while (node)
	{
		tmp = node->next;
		while (tmp)
		{
			if (node->num == tmp->num)
				err_exit(st, NULL, NULL);
			tmp = tmp->next;
		}
		node = node->next;
	}
}

static void	is_ok(t_stack *st_a, t_stack *st_b)
{
	if (st_b->size)
		write(1, "KO\n", 3);
	else if (is_sorted(st_a, st_a->size, 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;
	char	*str;

	init_stack(&st_a, &st_b);
	argv_to_stack(argv, st_a);
	invalid_check(st_a, st_a->top, 1);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		do_command(st_a, st_b, str);
		free(str);
	}
	is_ok(st_a, st_b);
	free_ps_stack(st_a);
	free_ps_stack(st_b);
	return (0);
}
