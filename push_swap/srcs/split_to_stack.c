/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:26:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/09 19:26:52 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_whitespace(char c)
{
	if ((c>=9 && c<= 13) || c == ' ')
		return (1);
	return (0);
}

int	ps_atoi(char *str, int offset)
{
	int		sign;
	int		nbr;
	size_t	i;

	sign = 1;
	nbr = 0;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (i < offset && str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + sign * (str[i] - '0');
		i++;
	}
	return (nbr);
}

t_stack	add_to_stack(int n, t_stack *st)
{
	t_stack	cur_stack;

	cur_stack.prevoius = st;
	cur_stack.next = NULL;
	cur_stack.num = n;
	if (st)
	{
		st->next = &cur_stack;
		cur_stack.top = st->top;
	}
	else
		cur_stack.top = &cur_stack;
	cur_stack.bottom = &cur_stack;
}

char	**split_to_stack(char const *s, t_stack *st)
{
	char	**res;
	size_t	offset;
	size_t	i;

	i = 0;
	while (*s)
	{
		offset = 0;
		if (is_whitespace(*s))
			s++;
		else
		{
			while (!is_whitespace(*(s + offset)) && *(s + offset)) // s ~ s+offset까지 단어
				offset++;
			st = add_to_stack(ps_atoi(s,offset), st);
		}
	}
	res[i] = 0;
	return (res);
}
