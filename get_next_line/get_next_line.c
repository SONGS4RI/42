/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/10 19:23:31 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <stdio.h>//////////////////
t_gnl_list	*del_gnl_list(t_gnl_list *tmp)
{
	t_gnl_list	*previous;

	if (tmp->previous)
	{
		previous = tmp->previous;
		previous->next = tmp->next;
	}
	free(tmp);
	return (NULL);
}

t_gnl_list	*find_fd(t_gnl_list *tmp, int fd, int cnt)
{
	while (tmp)
	{
		if (tmp->fd_idx == fd)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		return (tmp);
	else if (cnt > 0)
	{
		tmp = (t_gnl_list *)malloc(sizeof(t_gnl_list));
		if (!tmp)
			return (NULL);
		if (tmp->previous)
			tmp->previous->next = tmp;
		tmp->fd_idx = fd;
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}

char	*combine_buf_read(int len_s, char *s, int idx, t_gnl_list *buf)
{
	int		len;
	char	*tmp;

	len = len_s + idx;
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	if (buf->backup)
	{
		ft_strlcat(tmp, buf->backup, idx + 1);
		free(buf->backup);
	}
	ft_strlcat(tmp, s, len + 1);
	return (what_line(len_s, len, tmp, buf));
}

char	*what_line(int len_s, int len, char *tmp, t_gnl_list *buf)
{
	int		idx;
	char	*res;

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
	if (!buf)
		return (NULL);
	if (!cnt && !buf->backup)
	{
		del_gnl_list(buf);
		return (NULL);
	}
	if (buf->backup)
		buf_size = ft_strlen(buf->backup);
	return (combine_buf_read(cnt, next_line, buf_size, buf));
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	fd = open("files/nl",O_RDONLY);
// 	printf("--------------------\n");
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	// printf("|%s|\n",get_next_line(fd));
// 	// printf("|%s|\n",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// get_next_line(fd);
// 	// fd = open("./txt2.txt",O_RDONLY);
// 	// get_next_line(fd);
// 	// fd = open("./txt3.txt",O_RDONLY);
// 	// get_next_line(fd);

// }