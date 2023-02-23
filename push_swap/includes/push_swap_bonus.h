/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:50:02 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/23 15:23:24 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					num;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}t_stack_node;

typedef struct s_stack
{
	int					size;
	struct s_stack_node	*top;
	struct s_stack_node	*bottom;
}t_stack;

int				compare_num(int a, int b);
int				is_sorted(t_stack *st, int size, int sorted);
void			free_ps_stack(t_stack *st);
void			err_exit(t_stack *st, char *line);

static void		argv_to_stack(char **argv, t_stack *st);
static void		init_stack(t_stack **st_a, t_stack **st_b);
static void		invalid_check(t_stack *st, t_stack_node	*node, int sorted);

static int		is_whitespace(char c);
static int		ps_atoi(char *str, int offset, char *s, t_stack *st);
static void		add_to_stack(int n, char *s, t_stack *st);
void			split_to_stack(char *s, t_stack *st);

void			command_s(char c, t_stack *st_a, t_stack *st_b);
void			command_p(char c, t_stack *st_a, t_stack *st_b);
void			command_r(char c, t_stack *st_a, t_stack *st_b);
void			command_rr(char c, t_stack *st_a, t_stack *st_b);

t_stack_node	*popfront(t_stack *st);
t_stack_node	*popback(t_stack *st);
void			pushfront(t_stack_node *node, t_stack *to);
void			pushback(t_stack_node *node, t_stack *to);

#endif