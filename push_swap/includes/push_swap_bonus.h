/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:50:02 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/23 16:00:12 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

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

typedef struct s_gnl_list
{
	int					fd_idx;
	int					eof;
	int					no_nl_idx;
	struct s_gnl_list	*next;
	struct s_gnl_list	*previous;
	char				*backup;
}t_gnl_list;

int				compare_num(int a, int b);
int				is_sorted(t_stack *st, int size, int sorted);
void			free_ps_stack(t_stack *st);
void			err_exit(t_stack *st, char *line);

static void		argv_to_stack(char **argv, t_stack *st);
static void		init_stack(t_stack **st_a, t_stack **st_b);
static void		invalid_check(t_stack *st, t_stack_node	*node, int sorted);
static void		is_ok(t_stack *st_a, t_stack *st_b);

static int		is_whitespace(char c);
static int		ps_atoi(char *str, int offset, char *s, t_stack *st);
static void		add_to_stack(int n, char *s, t_stack *st);
void			split_to_stack(char *s, t_stack *st);

void			do_command_s(t_stack *st_a, t_stack *st_b, char *str);
void			do_command_p(t_stack *st_a, t_stack *st_b, char *str);
void			do_command_r(t_stack *st_a, t_stack *st_b, char *str);
void			do_command(t_stack *st_a, t_stack *st_b, char *str);

void			command_s(char c, t_stack *st_a, t_stack *st_b);
void			command_p(char c, t_stack *st_a, t_stack *st_b);
void			command_r(char c, t_stack *st_a, t_stack *st_b);
void			command_rr(char c, t_stack *st_a, t_stack *st_b);

t_stack_node	*popfront(t_stack *st);
t_stack_node	*popback(t_stack *st);
void			pushfront(t_stack_node *node, t_stack *to);
void			pushback(t_stack_node *node, t_stack *to);

t_gnl_list		*del_gnl_list(t_gnl_list **tmp);
t_gnl_list		*find_fd(t_gnl_list *tmp, int fd, t_gnl_list	*head);
char			*combine_all(char **str1, char **str2, t_gnl_list **tmp);
char			*read_line(t_gnl_list **tmp, int fd);
char			*get_next_line(int fd);
size_t			ft_len_free(const char *s, char **free_s);
size_t			ft_gnlcpy(char *dst, char *src, size_t dstsize, size_t idx);
char			*ft_gnlstr(char *s, int start, size_t len, t_gnl_list **tmp);
char			*is_nl_backup(char **str, int len, t_gnl_list *tmp);
char			*is_nl_line(char **str, int len, t_gnl_list **tmp, int idx);

#endif