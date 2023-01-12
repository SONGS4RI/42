/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/12 17:04:16 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <stdio.h>//////////////////
char	*del_gnl_list(t_gnl_list *tmp)
{
	t_gnl_list	*previous;

	if (tmp && tmp->previous)
	{
		// printf("connect list!!!\n");///////////////////////////////
		previous = tmp->previous;
		previous->next = tmp->next;
	}
	if (tmp && tmp->backup)
	{
		// printf("#free tmp->backup at %p\n",tmp->backup);///////////////////////////////
		free(tmp->backup);
		tmp->backup = NULL;
	}
	if (tmp)
	{
		tmp->next = NULL;
		tmp->previous = NULL;
		free(tmp);
		// printf("#free list(*tmp_address) at %p\n",tmp);///////////////////////////////
	}
	return (NULL);
}

t_gnl_list	*find_fd(t_gnl_list *tmp, int fd)
{
	t_gnl_list	*head;

	if (tmp && tmp->eof)
		return (NULL);
	while (tmp)
	{
		if (tmp->fd_idx == fd)
			break ;
		tmp = tmp->next;
	}
	head = tmp;
	if (tmp)
		return (tmp);
	else
	{
		tmp = (t_gnl_list *)malloc(sizeof(t_gnl_list));
		// printf("#malloced list at %p\n",tmp);////////////////////////////////////////
		if (!tmp)
			return (NULL);
		if (head)
			tmp->previous->next = tmp;
		tmp->eof = 0;
		tmp->fd_idx = fd;
		tmp->next = NULL;
		return (tmp);
	}
}

char	*buf_read(int len_read, char *s, int len_buf, t_gnl_list *buf)
{
	int		len;
	char	*tmp;

	len = len_read + len_buf;
	tmp = (char *)malloc(len + 1);
	// printf("#malloced tmp(read+buf) at %p\n",tmp);///////////////////////////////////
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	if (buf->backup)
	{
		ft_strlcat(tmp, buf->backup, len_buf + 1);
		free(buf->backup);
		// printf("#freed buf->backup at %p\n",buf->backup);///////////////////////////////////
		buf->backup = NULL;
	}
	ft_strlcat(tmp, s, len + 1);
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
			res = ft_substr(tmp, 0, len);//malloc!!!!!!!!!!!!!!
			free(tmp);
			// printf("#freed tmp(read+buf) at %p\n",tmp);///////////////////////////////////
			buf->eof = 1;
			return (res);
		}
		buf->backup = ft_substr(tmp, 0, len);
		free(tmp);
		// printf("#freed tmp(read+buf) at %p\n",tmp);///////////////////////////////////
		return (NULL);
	}
	else
	{
		buf->backup = ft_substr(tmp, idx + 1, len);
		// printf("#malloced buf->backup at %p\n",buf->backup);///////////////////////////////////
	}
	res = ft_substr(tmp, 0, idx + 1);
	free(tmp);
	// printf("#freed tmp(read+buf) at %p\n",tmp);/////////////////////////////////////////////////
	return (res);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	char				next_line[BUFFER_SIZE];
	char				*res;
	int					buf_size;
	int					cnt;

	// printf("--------------------\n");///////////////////////////////////////////////////
	// printf("head pointing at %p\n",head);/////////////////////////////////////////////////
	buf_size = 0;
	if (fd < 0)
		return (NULL);
	cnt = read(fd, next_line, BUFFER_SIZE);
	// write(1,"read :|",7); write(1,next_line,cnt);write(1,"|\n",2);/////////////////////////////
	head = find_fd(head, fd);
	// printf("head pointing after find_fd at %p\n",head);//////////////////////////////
	// if (head->backup) printf("buf->backup now:|%s|\n",head->backup);/////////////////////////
	if (head->backup)
		buf_size = ft_strlen(head->backup);
	res = buf_read(cnt, next_line, buf_size, head);
	if (head->eof)
		head = (t_gnl_list *)del_gnl_list(head);
	return (res);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	int num = 2;
// 	fd = open("files/empty",O_RDONLY);
// 	for(int i=1;i<=num;i++)
// 		printf("num:%d ---->|%s|\n",i,get_next_line(1000));
// }