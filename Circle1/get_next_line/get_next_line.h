/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:16:28 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/24 17:27:09 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_gnl_list
{
	int					fd_idx;
	int					eof;
	int					no_nl_idx;
	struct s_gnl_list	*next;
	struct s_gnl_list	*previous;
	char				*backup;
}t_gnl_list;

t_gnl_list	*del_gnl_list(t_gnl_list **tmp);
t_gnl_list	*find_fd(t_gnl_list *tmp, int fd, t_gnl_list	*head);
char		*combine_all(char **str1, char **str2, t_gnl_list **tmp);
char		*read_line(t_gnl_list **tmp, int fd);
char		*get_next_line(int fd);
size_t		ft_len_free(const char *s, char **free_s);
size_t		ft_gnlcpy(char *dst, char *src, size_t dstsize, size_t idx);
char		*ft_gnlstr(char *s, int start, size_t len, t_gnl_list **tmp);
char		*is_nl_backup(char **str, int len, t_gnl_list *tmp);
char		*is_nl_line(char **str, int len, t_gnl_list **tmp, int idx);

#endif
