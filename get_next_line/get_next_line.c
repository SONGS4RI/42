/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/07 21:31:03 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>///////

t_gnl_list	*find_fd(t_gnl_list *tmp, int fd)
{
	t_gnl_list	*new;

	while (tmp)
	{
		if (tmp->fd_idx == fd)
			break ;
		new = tmp;
		tmp = tmp->next;
	}
	if (tmp)//존재하는 리스트면 그떄의 노드 반환
	{
		printf("found\n");//왜안나오지????
		return (tmp);
	}
	else
	{
		printf("new\n");
		tmp = (t_gnl_list *)malloc(sizeof(t_gnl_list));
		tmp->fd_idx = fd;
		// printf("%d\n",new->fd_idx);
		tmp->next = NULL;
		if(new)
			new->next = tmp;
		return (tmp);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	t_gnl_list			*buf;
	char				*next_line;

	if (fd < 0)
		return (NULL);
	if(!head)
		head = find_fd(head,fd);
	else
		buf = find_fd(head, fd);
	return ("done");
}
////////////////////////////////////////////////////////////////
#include <fcntl.h>
int main()
{
	static t_gnl_list	*head;
	t_gnl_list *tmp;
	int fd;

	fd = open("./txt1.txt",O_RDONLY);
	get_next_line(fd);
	fd = open("./txt2.txt",O_RDONLY);
	get_next_line(fd);
	fd = open("./txt3.txt",O_RDONLY);
	get_next_line(fd);
	fd = open("./txt2.txt",O_RDONLY);
	get_next_line(fd);
}