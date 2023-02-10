/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:18:47 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/10 13:30:55 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_ps_stack(t_stack *st)
{
	t_stack *tmp;

	while(st)
	{
		tmp = st->next;
		free(st);
		st = tmp;
	}
}

void	err_exit(t_stack *st, char *line, char *err_msg)
{
	write(2, "Error\n", 6);
	write(2, err_msg, ft_strlen(err_msg));
	if (line)
		free(line);
	free_ps_stack(st);
	exit(1);
}