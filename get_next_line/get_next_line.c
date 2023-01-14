/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/14 21:41:15 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*del_gnl_list(t_gnl_list *tmp)
{
	t_gnl_list	*previous;

	if (tmp->previous)
	{
		previous = tmp->previous;
		previous->next = tmp->next;
	}
	if (tmp->backup)
		free(tmp->backup);
	tmp->backup = NULL;
	tmp->next = NULL;
	tmp->previous = NULL;
	free(tmp);
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

char	*combine_all(t_gnl_list	*tmp, char *next_line, int read_cnt)
{
	char	*res;
	int		back_up_size;

	back_up_size = 0;
	if (tmp->backup)
		back_up_size = ft_strlen(tmp->backup);
	res = (char *)malloc(sizeof(char *) * (back_up_size + read_cnt + 1));
	if (!res)
		return (NULL);
	res[0] = '\0';
	if (tmp->backup)
	{
		ft_strlcat(res, tmp->backup, back_up_size, back_up_size + 1);
		free(tmp->backup);
		tmp->backup = NULL;
	}
	ft_strlcat(res, next_line, read_cnt, back_up_size + read_cnt + 1);
	return (res);
}

char	*res_line(t_gnl_list	*head, char *tmp, int idx)
{
	char	*res;
	int		len;

	len = ft_strlen(tmp);
	res = ft_substr(tmp, 0, idx);
	if (len > idx)
		head->backup = ft_substr(tmp, idx + 1, len);
	free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	char				next_line[BUFFER_SIZE];
	char				*tmp;
	int					idx;
	int					read_cnt;

	if (fd < 0)
		return (NULL);
	head = find_fd(head, fd, read_cnt);
	if (!head)
		return (NULL);
	while (1)
	{
		read_cnt = read(fd, next_line, BUFFER_SIZE);
		tmp = combine_all(head, next_line, read_cnt);//버퍼 + next_line, 버퍼 프리
		idx = is_nl(tmp, read_cnt, head->backup); // 없으면 버퍼에 세이브;
		if (idx)
			return (res_line(head, tmp, idx));// 개행 존재하면 인덱스 까지 출력 해주고 버퍼에 세이브해주는 함수 && idx 부터 버퍼에 저장
	}
	return (NULL);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	int num = 3;
// 	fd = open("files/1char",O_RDONLY);
// 	for(int i=1;i<=num;i++)
// 		printf("num:%d ---->|%s|\n",i,get_next_line(fd));
// }
