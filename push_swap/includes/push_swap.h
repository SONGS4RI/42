/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:50:02 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/10 13:34:02 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack *next;
	struct s_stack *prevoius;
	struct s_stack *top;
	struct s_stack *bottom;
}t_stack;

t_stack	*init_a(char **argv, t_stack *st);

void	free_ps_stack(t_stack *st);
void	err_exit(t_stack *st, char *line, char *err_msg);

static int	is_whitespace(char c);
static int	ps_atoi(char *str, int offset);
static t_stack	*add_to_stack(int n, char *s, t_stack *st);
t_stack	*split_to_stack(char *s, t_stack *st);


#endif