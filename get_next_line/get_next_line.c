/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/10 17:47:25 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*del_gnl_list(t_gnl_list *tmp)
{
	t_gnl_list	*previous;

	previous = tmp->previous;
	previous->next = tmp->next;
	if (tmp->backup)
		free(tmp->backup);
	free(tmp);
	return (NULL);
}

t_gnl_list	*find_fd(t_gnl_list *tmp, int fd, int cnt)
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
	else if (cnt)
	{
		tmp = (t_gnl_list *)malloc(sizeof(t_gnl_list));
		if (!tmp)
			return (NULL);
		tmp->previous = new;
		tmp->fd_idx = fd;
		tmp->next = NULL;
		if (new)
			new->next = tmp;
		return (tmp);
	}
	return (NULL);
}

char	*is_backup(int len_s, char *s, int idx, t_gnl_list *buf)
{
	int		len;
	char	*tmp;
	char	*res;

	len = len_s + idx;
	tmp = (char *)malloc(len + 1);
	tmp[0] = '\0';
	if (!tmp)
		return (NULL);
	if (buf->backup)
	{
		ft_strlcat(tmp, buf->backup, idx + 1);
		free(buf->backup);
	}
	ft_strlcat(tmp, s, len + 1);
	idx = 0;
	while (tmp[idx] != '\n' && tmp[idx])
		idx++;
	if (idx == len)
	{
		if (len_s != len)
		{
			free(buf);
			free(tmp);
			return (NULL);
		}
		buf->backup = ft_substr(tmp, 0, len);
		free(tmp);
		return (NULL);
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
	cnt = read(fd, next_line, BUFFER_SIZE);
	if (!head)
		head = find_fd(head, fd, cnt);
	buf = find_fd(head, fd, cnt);
	if (!cnt && !buf->backup)
	{
		del_gnl_list(buf);
		return (NULL);
	}
	if (buf->backup)
		buf_size = ft_strlen(buf->backup);
	return (is_backup(cnt, next_line, buf_size, buf));
}
