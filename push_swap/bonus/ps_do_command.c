/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:48:20 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/23 15:53:11 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	do_command_s(t_stack *st_a, t_stack *st_b, char *str)
{
	if (str[1] == 'a')
		command_s('a', st_a, st_b);
	else if (str[1] == 'b')
		command_s('b', st_a, st_b);
	else if (str[1] == 's')
		command_s('s', st_a, st_b);
}

void	do_command_p(t_stack *st_a, t_stack *st_b, char *str)
{
	if (str[1] == 'a')
		command_p('a', st_a, st_b);
	else if (str[1] == 'b')
		command_p('b', st_a, st_b);
}

void	do_command_r(t_stack *st_a, t_stack *st_b, char *str)
{
	if (str[1] == 'a')
		command_r('a', st_a, st_b);
	else if (str[1] == 'b')
		command_r('b', st_a, st_b);
	else if (str[1] == 'r' && str[2] == '\n')
		command_r('r', st_a, st_b);
	else if (str[1] == 'r' && str[2] == 'a')
		command_rr('a', st_a, st_b);
	else if (str[1] == 'r' && str[2] == 'b')
		command_rr('b', st_a, st_b);
	else if (str[1] == 'r' && str[2] == 'r')
		command_rr('r', st_a, st_b);
}

void	do_command(t_stack *st_a, t_stack *st_b, char *str)
{
	if (str[0] == 's')
		do_command_s(st_a, st_b, str);
	else if (str[0] == 'p')
		do_command_p(st_a, st_b, str);
	else if (str[0] == 'r')
		do_command_r(st_a, st_b, str);
}
