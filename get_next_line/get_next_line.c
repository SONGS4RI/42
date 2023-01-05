/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/05 20:59:14 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>///////

t_gnl_list	*find_fd(t_gnl_list *tmp, int fd)
{
	t_gnl_list	*new;

	while (tmp->next)
	{
		if (tmp->fd_idx == fd)
			break ;
		tmp = tmp->next;
	}
	if (tmp->next)
		return (tmp);
	else
	{
		tmp->next = new_fd(new, fd);
	}
}

t_gnl_list	*new_fd(t_gnl_list *tmp, int fd)
{
	tmp = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	tmp->fd_idx = fd;
	tmp->next = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	t_gnl_list			*buf;
	char				*next_line;

	if (fd < 0)
		return (NULL);
	if (!head)
		head = new_fd(head, fd);
	else
		buf = find_fd(head, fd);
	return ("good");
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
}