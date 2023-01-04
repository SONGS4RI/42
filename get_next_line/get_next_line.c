/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/04 20:19:19 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>///////

// t_gnl_list	*find_fd(t_gnl_list *head, int fd)
// {
// 	while (head->next)
// 	{
// 		if (head->next->fd_idx == fd)
// 			break ;
// 		head = head->next;
// 	}
// 	if (!head)
// 		return (new_fd(head, fd)->next);
// 	else
// 		return (head->next);
// }

// t_gnl_list	*new_fd(t_gnl_list *head, int fd)
// {
// 	t_gnl_list	*new;

// 	head->next = new;
// 	new->fd_idx = fd;
// 	new->next = NULL;
// 	return (new);
// }

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	t_gnl_list			*buf;
	char				*next_line;

	if (fd < 0)
		return (NULL);
	// fd값이랑 일치하는 리스트가 있는지 확인
	//find_fd(head,fd);
	
	return (next_line);
}
////////////////////////////////////////////////////////////////
#include <fcntl.h>
int main()
{
	static t_gnl_list	*head;
	t_gnl_list *tmp;
	int fd;

	tmp = head;
	// fd = open("./txt1.txt",O_RDONLY);
	if(!head->fd_idx) printf("NULL\n");
}