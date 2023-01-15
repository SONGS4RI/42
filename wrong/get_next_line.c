/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/14 19:33:48 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <stdio.h>//////////////////
char	*del_gnl_list(t_gnl_list *tmp)
{
	t_gnl_list	*previous;

	if (tmp->previous)
	{
		previous = tmp->previous;
		previous->next = tmp->next;
	}
	if (tmp->backup)
	{
		// printf("#free tmp->backup at %p\n",tmp->backup);///////////////////////////////
		free(tmp->backup);
	}
	tmp->backup = NULL;
	tmp->next = NULL;
	tmp->previous = NULL;
	free(tmp);
	// printf("#free list(*tmp) at %p\n",tmp);///////////////////////////////
	tmp = NULL;
	return (NULL);
}

t_gnl_list	*find_fd(t_gnl_list *tmp, int fd, int read_cnt)
{
	t_gnl_list	*head;

	while (tmp)
	{
		if (tmp->fd_idx == fd)
			break ;
		tmp = tmp->next;
	}
	head = tmp;
	if (tmp)
		return (tmp);
	else if (read_cnt > 0)
	{
		tmp = (t_gnl_list *)malloc(sizeof(t_gnl_list));
		// printf("#malloced list at %p\n",tmp);////////////////////////////////////////
		if (!tmp)
			return (NULL);
		if (head)
			tmp->previous->next = tmp;
		tmp->previous = NULL;
		tmp->backup = NULL;
		tmp->eof = 0;
		tmp->fd_idx = fd;
		tmp->next = NULL;
	}
	return (tmp);
}

char	*buf_read(int len_read, char *s, int len_buf, t_gnl_list *buf)
{
	int		len;
	char	*tmp;

	len = len_read + len_buf;
	// printf("read_bytes :%d || len_buf :%d || len :%d\n",len_read,len_buf,len);//////////////////////////////////////////////////////////
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	// printf("#malloced tmp(read+buf) at %p\n",tmp);///////////////////////////////////
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	if (buf->backup)
	{
		ft_strlcat(tmp, buf->backup, len_buf, len_buf + 1);
		free(buf->backup);
		// printf("#freed buf->backup at %p\n",buf->backup);///////////////////////////////////
		buf->backup = NULL;
	}
	if (len_read > 0)
		ft_strlcat(tmp, s, len_read, len + 1);
	free(s);
	// printf("tmp string :|%s|\n",tmp);/////////////////////////////////////////////////
	return (what_line(len_read, len, tmp, buf));
}

char	*what_line(int len_read, int len, char *tmp, t_gnl_list *buf)
{
	int		idx;
	char	*res;

	idx = 0;
	while (tmp[idx] != '\n' && tmp[idx])
		idx++;
	if (idx >= len)
	{
		if (len_read < BUFFER_SIZE)
		{
			res = ft_substr(tmp, 0, idx);
			free(tmp);
			// printf("#freed tmp(read+buf) at %p\n",tmp);///////////////////////////////////
			buf->eof = 1;
			return (res);
		}
		buf->backup = ft_substr(tmp, 0, idx);
		// printf("#malloced buf->backup at %p\n",buf->backup);///////////////////////////////////
		free(tmp);
		// printf("#freed tmp(read+buf) at %p\n",tmp);///////////////////////////////////
		return (NULL);
	}
	res = ft_substr(tmp, 0, idx + 1);
	buf->backup = ft_substr(tmp, idx + 1, len);
	// printf("#malloced buf->backup at %p\n",buf->backup);///////////////////////////////////
	free(tmp);
	// printf("#freed tmp(read+buf) at %p\n",tmp);/////////////////////////////////////////////////
	return (res);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	char				*next_line;
	char				*res;
	int					buf_size;
	int					cnt;

	// printf("-----------------------\n");///////////////////////////////////////////////////
	// printf("head pointing at %p\n",head);/////////////////////////////////////////////////
	buf_size = 0;
	if (fd < 0)
		return (NULL);
	next_line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!next_line)
		return (NULL);
	cnt = read(fd, next_line, BUFFER_SIZE);
	// write(1,"read :|",7); write(1,next_line,cnt);write(1,"|\n",2);/////////////////////////////
	head = find_fd(head, fd, cnt);
	if (!head)
	{
		free(next_line);
		return (NULL);
	}
	// printf("head pointing after find_fd at %p\n",head);//////////////////////////////
	// if (head->backup) printf("buf->backup :|%s|\n",head->backup);/////////////////////////
	if (head->backup)
		buf_size = ft_strlen(head->backup);
	res = buf_read(cnt, next_line, buf_size, head);
	if (head->eof)
		head = (t_gnl_list *)del_gnl_list(head);
	return (res);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	int num = 3;
	fd = open("files/1char",O_RDONLY);
	for(int i=1;i<=num;i++)
		printf("num:%d ---->|%s|\n",i,get_next_line(fd));
}




/*
아마 substr하면서 말록 하지 않는 부분이 생겨서 free 할 때 겹치는 듯?????
*/