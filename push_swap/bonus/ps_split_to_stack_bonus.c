/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split_to_stack_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:26:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/23 20:13:32 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	ps_atoi(char *str, int offset, char *s, t_stack *st)
{
	int				sign;
	long long		nbr;
	size_t			i;

	sign = 1;
	nbr = 0;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	if (str[i] == '\0' || !((str[i] >= '0') && (str[i] <= '9')))
		err_exit(st, NULL, s);
	while (i < offset && str[i])
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
			nbr = (nbr * 10) + sign * (str[i] - '0');
		else
			err_exit(st, NULL, s);
		i++;
	}
	if (i > 11 || nbr > 2147483647 || nbr < -2147483648)
		err_exit(st, NULL, s);
	return (nbr);
}

static void	add_to_stack(int n, char *s, t_stack *st)
{
	t_stack_node	*cur_node;

	cur_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!cur_node)
		err_exit(st, NULL, s);
	if (!st->top)
	{
		st->top = cur_node;
		st->bottom = cur_node;
		cur_node->previous = NULL;
	}
	else
	{
		st->bottom->next = cur_node;
		cur_node->previous = st->bottom;
		st->bottom = cur_node;
	}
	st->size++;
	cur_node->next = NULL;
	cur_node->num = n;
}

void	split_to_stack(char *s, t_stack *st)
{
	size_t	offset;
	size_t	i;
	char	*tmp;

	tmp = s;
	i = 0;
	while (*tmp)
	{
		offset = 0;
		if (is_whitespace(*tmp))
			tmp++;
		else
		{
			while (!is_whitespace(*(tmp + offset)) && *(tmp + offset))
				offset++;
			add_to_stack(ps_atoi(tmp, offset, s, st), s, st);
			tmp += offset;
		}
	}
	free(s);
}
