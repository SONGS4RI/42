/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/09 20:33:48 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*find_fd(t_gnl_list *tmp, int fd)
{
	t_gnl_list	*new;

	new = tmp;
	while (tmp)
	{
		if (tmp->fd_idx == fd)
			break ;
		new = tmp;
		tmp = tmp->next;
	}
	if (tmp)
		return (tmp);
	else
	{
		tmp = (t_gnl_list *)malloc(sizeof(t_gnl_list));
		if (!tmp)
			return (NULL);
		tmp->fd_idx = fd;
		tmp->next = NULL;
		if (new)
			new->next = tmp;
		return (tmp);
	}
}

char	*is_backup(int len_s, char *s, int len_buf, t_gnl_list *buf)
{
	int		len;
	char	*tmp;
	char	*res;
	int		idx;

	idx = 0;
	len = len_s + len_buf;
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	if (buf->backup)
	{
		ft_strlcat(tmp, buf->backup, len + 1);
		free(buf->backup);
	}
	ft_strlcat(tmp, s, len + 1);
	while (tmp[idx] != '\n' && tmp[idx])
		idx++;
	if (idx == len)//개행이 없다는 뜻
	{
		if (len_s != BUFFER_SIZE)//마지막 읽기이면
		{
			free(buf->backup);
			free(buf);
			return (NULL);
		}
		buf->backup = ft_substr(tmp, 0, idx + 1);;
	}
	else
		buf->backup = ft_substr(tmp, idx + 1, len);
	res = ft_substr(tmp, 0, idx + 1);
	free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	t_gnl_list			*buf;
	char				next_line[BUFFER_SIZE];
	int					buf_size;
	int					cnt;

	buf_size = 0;
	if (fd < 0)
		return (NULL);
	if (!head)
		head = find_fd(head, fd);
	buf = find_fd(head, fd);
	cnt = read(fd, next_line, BUFFER_SIZE);
	if (!cnt && !buf->backup)//eof고 버퍼에 값들어있으면
	{
		free(buf->backup);
		free(buf);
		return (NULL);
	}
	if (buf->backup)
		buf_size = ft_strlen(buf->backup);
	return (is_backup(cnt, next_line, buf_size, buf));
}
