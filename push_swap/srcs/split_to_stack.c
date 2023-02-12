/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:26:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/12 17:58:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	ps_atoi(char *str, int offset)
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

static void	add_to_stack(int n, char *s, t_stack **st)
{
	t_stack_node	*cur_node;

	cur_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!cur_node)
		err_exit(*st, s, "malloc err : add_to_stack\n");
	if (!(*st)->top)
	{
		(*st)->top = cur_node;
		(*st)->bottom = cur_node;
		cur_node->prevoius = NULL;
	}
	else
	{
		(*st)->bottom->next = cur_node;
		cur_node->prevoius = (*st)->bottom;
		(*st)->bottom = cur_node;
	}
	cur_node->next = NULL;
	cur_node->num = n;
}

void	split_to_stack(char *s, t_stack **st)
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
			add_to_stack(ps_atoi(tmp, offset), s, st);
			tmp += offset;
		}
	}
	free(s);
}
