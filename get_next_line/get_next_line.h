/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:16:28 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/17 20:02:05 by jahlee           ###   ########.fr       */
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
	struct s_gnl_list	*next;
	struct s_gnl_list	*previous;
	char				*backup;
}t_gnl_list;

size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *s, size_t s_len, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			is_nl(char *tmp, int read_cnt, t_gnl_list *head);
t_gnl_list	*del_gnl_list(t_gnl_list *tmp);
t_gnl_list	*find_fd(t_gnl_list *tmp, int fd, int read_cnt);
char		*combine_all(t_gnl_list	*tmp, char *next_line, int read_cnt);
char		*res_line(t_gnl_list	*head, char *tmp, int idx);
char		*get_next_line(int fd);
#endif
