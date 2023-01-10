/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/10 16:42:19 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//

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
		tmp->fd_idx = fd;
		tmp->next = NULL;
		if (new)
			new->next = tmp;
		return (tmp);
	}
	return (NULL);
}

char	*is_backup(int len_s, char *s, int len_buf, t_gnl_list *buf)//eof && 버퍼에 값있을때
{
	int		len;
	char	*tmp;
	char	*res;
	int		idx;

	idx = 0;
	len = len_s + len_buf;
	tmp = (char *)malloc(len + 1);
	tmp[0] = '\0';
	if (!tmp)
		return (NULL);//백업 다  널처리
	if (buf->backup)// 버퍼가 존재하면
	{
		ft_strlcat(tmp, buf->backup, len_buf + 1);
		free(buf->backup);
	}
	ft_strlcat(tmp, s, len + 1);
	printf("tmp(readall) : |%s|\n",tmp);/////////////////////
	while (tmp[idx] != '\n' && tmp[idx])
		idx++;
	if (idx == len)
	{
		if (len_s != len)//eof
		{
			free(buf);
			free(tmp);
			printf("buf_new(no\\n&&eof)\n");/////////////
			return (NULL);
		}
		buf->backup = ft_substr(tmp, 0, len);
		free(tmp);
		printf("buf_new(no\\n&&noteof) :start|%s|end\n",buf->backup);/////////////
		return (NULL);
	}
	else
		buf->backup = ft_substr(tmp, idx + 1, len);
	res = ft_substr(tmp, 0, idx + 1);
	printf("buf_new:start|%s|end\n",buf->backup);/////////////
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
	printf("-------------------------------------------\n");///////////////////
	write(1,"read : |",8);
	write(1,next_line,cnt);
	write(1,"|\n",2);
	if (!head)
		head = find_fd(head, fd, cnt);
	buf = find_fd(head, fd, cnt);
	if (!cnt && !buf->backup)//eof && 버퍼에 아무것도 없으면
	{
		free(buf);
		printf("eof && nobuf\n");
		return (NULL);
	}
	if (buf->backup)
	{
		printf("buf->backup_present: |%s|\n",buf->backup);/////////////
		buf_size = ft_strlen(buf->backup);
	}
	return (is_backup(cnt, next_line, buf_size, buf));
}
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("./txt1.txt",O_RDONLY);
	printf("gnl == |%s|\n",get_next_line(fd));
	printf("gnl == |%s|\n",get_next_line(fd));
	printf("gnl == |%s|\n",get_next_line(fd));
	printf("gnl == |%s|\n",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// get_next_line(fd);
	// fd = open("./txt2.txt",O_RDONLY);
	// get_next_line(fd);
	// fd = open("./txt3.txt",O_RDONLY);
	// get_next_line(fd);

}