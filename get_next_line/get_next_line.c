/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/11 20:49:21 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//////////////////
char	*del_gnl_list(t_gnl_list **tmp_address, t_gnl_list *tmp)
{
	t_gnl_list	*previous;

	printf("del list!!!!!!!!!!!\n");/////////////////////////////////
	if (tmp->previous)
	{
		previous = tmp->previous;
		previous->next = tmp->next;
	}
	if (tmp->backup)
	{
		free(tmp->backup);
		tmp->backup = NULL;
	}
	if (tmp)
	{
		free(*tmp_address);
		*tmp_address = NULL;
	}
	// if(!tmp_address) printf("good\n");////////////////////////////////////
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
	else if (cnt > 0)//////////wrong??////////////
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

char	*combine_buf_read(int len_read, char *s, int len_buf, t_gnl_list *buf)
{
	int		len;
	char	*tmp;

	len = len_read + len_buf;
	tmp = (char *)malloc(len + 1);//malloc!!!!!!!!!!!!!!
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	if (buf->backup)
	{
		ft_strlcat(tmp, buf->backup, len_buf + 1);
		free(buf->backup);
		buf->backup = NULL;
	}
	ft_strlcat(tmp, s, len + 1);
	printf("tmp string :|%s|\n",tmp);/////////////////////////////////////////////////
	return (what_line(len_read, len, tmp, buf));
}

char	*what_line(int len_read, int len, char *tmp, t_gnl_list *buf)
{
	int		idx;
	char	*res;

	idx = 0;
	while (tmp[idx] != '\n' && tmp[idx])
		idx++;
	if (idx == len)
	{
		if (len_read < BUFFER_SIZE)
		{
			res = ft_substr(tmp, 0, len);//malloc!!!!!!!!!!!!!!
			free(tmp);
			del_gnl_list(&buf, buf);
			return (res);
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
	char				next_line[BUFFER_SIZE];
	int					buf_size;
	int					cnt;

	printf("--------------------\n");///////////////////////////////////////////////////
	buf_size = 0;
	if (fd < 0)
		return (NULL);
	cnt = read(fd, next_line, BUFFER_SIZE);
	write(1,"read :|",7); write(1,next_line,cnt);write(1,"|\n",2);/////////////////////////////
	if (!head) printf("head NULL\n");///////////////////////////////////////////
		// return (NULL);
	head = find_fd(head, fd, cnt);
	// if (head->backup) printf("buf->backup now:|%s|\n",head->backup);/////////////////////////
	if (head->backup)
		buf_size = ft_strlen(head->backup);
	printf("cnt: %d, buf_siuze: %d\n", cnt, buf_size);//////////////////////./////////////////
	return (combine_buf_read(cnt, next_line, buf_size, head));
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	int num = 3;
	fd = open("files/nl",O_RDONLY);
	for(int i=1;i<=num;i++)
		printf("num:%d ---->|%s|\n",i,get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("|%s|\n",get_next_line(fd));
	// printf("|%s|\n",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// get_next_line(fd);
	// fd = open("./txt2.txt",O_RDONLY);
	// get_next_line(fd);
	// fd = open("./txt3.txt",O_RDONLY);
	// get_next_line(fd);

}