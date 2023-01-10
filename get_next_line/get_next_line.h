/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:16:28 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/10 17:32:38 by jahlee           ###   ########.fr       */
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
	char				*backup;
	struct s_gnl_list	*next;
	struct s_gnl_list	*previous;
}t_gnl_list;

size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_substr(char const *s, unsigned int start, size_t len);
t_gnl_list	*del_gnl_list(t_gnl_list *tmp);
t_gnl_list	*find_fd(t_gnl_list *tmp, int fd, int cnt);
char		*is_backup(int len_s, char *s, int len_buf, t_gnl_list *buf);
char		*get_next_line(int fd);
#endif