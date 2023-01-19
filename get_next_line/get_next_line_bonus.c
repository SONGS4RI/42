/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/19 17:04:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>/////////////////////

t_gnl_list	*del_gnl_list(t_gnl_list *tmp)
{
	t_gnl_list	*head;

	head = tmp;
	if (tmp)
	{
		if (tmp->previous)
		{
			tmp->previous->next = tmp->next;
			if (tmp->next)
				tmp->next->previous = tmp->previous;
			while (head->previous)
				head = head->previous;
		}
		else if (tmp->next)
		{
			tmp->next->previous = NULL;
			head = tmp->next;
		}
		else
			head = NULL;
		if (tmp->backup)
			free(tmp->backup);
		free(tmp);
		printf("freed at %p\n",tmp);///////////////////////////////
	}
	return (head);
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
		printf("malloc at %p\n",tmp);///////////////////////////////
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
	if (!tmp || read_cnt == -1)
		return (NULL);
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

	if (!head)
		return (NULL);
	len = ft_strlen(tmp);
	res = ft_substr(tmp, 0, idx + 1);
	if (len > idx + 1)
		head->backup = ft_substr(tmp, idx + 1, len);
	free(tmp);
	tmp = NULL;
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
	printf("head pointing at %p\n",head);///////////////////////////////////
	while (1)
	{
		read_cnt = read(fd, next_line, BUFFER_SIZE);
		head = find_fd(head, fd, read_cnt);
		tmp = combine_all(head, next_line, read_cnt);
		idx = is_nl(tmp, read_cnt, head);
		if (idx == -1 || !head)
			head = del_gnl_list(head);
		if (idx == 0)
			continue ;
		tmp = res_line(head, tmp, idx - 1);
		if (!tmp || head->eof)
			head = del_gnl_list(head);
		return (tmp);
	}
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd[3];
	fd[0] = open("./files/1",O_RDONLY);
	fd[1] = open("./files/2",O_RDONLY);
	fd[2] = open("./files/3",O_RDONLY);
	printf("|%s|\n",get_next_line(fd[0]));
	printf("|%s|\n",get_next_line(fd[1]));
	printf("|%s|\n",get_next_line(fd[2]));
	printf("|%s|\n",get_next_line(fd[0]));
	printf("|%s|\n",get_next_line(fd[1]));
	printf("|%s|\n",get_next_line(fd[2]));
	printf("|%s|\n",get_next_line(fd[0]));
	printf("|%s|\n",get_next_line(fd[1]));
	printf("|%s|\n",get_next_line(fd[2]));
	/*
		del을 안했을때 head가 가리키는곳 초기화
	*/
}