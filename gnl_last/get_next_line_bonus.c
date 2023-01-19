/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/19 17:40:25 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>/////////////////////

t_gnl_list	*del_gnl_list(t_gnl_list *tmp)
{
	t_gnl_list	*head;

	head = NULL;
	if (tmp->previous)
	{
		tmp->previous->next = tmp->next;
		if (tmp->next)
			tmp->next->previous = tmp->previous;
		while (head)
			head = head->previous;
	}
	else if (tmp->next)
	{
		tmp->next->previous = NULL;
		head = tmp->next;
	}
	if (tmp->backup)
		free(tmp->backup);
	free(tmp);
	// printf("list freed at %p\n",tmp);////////////////////////
	return (head);
}

t_gnl_list	*find_fd(t_gnl_list *tmp, int fd, t_gnl_list	*head)
{
	while (tmp)
	{
		if (tmp->fd_idx == fd)
			break ;
		head = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
	{
		tmp = (t_gnl_list *)malloc(sizeof(t_gnl_list));
		if (!tmp)
			return (NULL);
		// printf("list malloced at %p\n",tmp);////////////////////////
		tmp->previous = NULL;
		tmp->next = NULL;
		tmp->backup = NULL;
		tmp->fd_idx = fd;
		if (head)
		{
			head->next = tmp;
			tmp->previous = head;
		}
	}
	return (tmp);
}

char	*combine_all(t_gnl_list	*tmp, char *next_line, int read_cnt)
{

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
	t_gnl_list			*tmp;
	char				*line;
	char				*res;
	int					read_cnt;

	if (fd < 0)
		return (NULL);
	if (!head)
			head = find_fd(head, fd, NULL);
	tmp = find_fd(head, fd, NULL);
	if (tmp->backup)
		is_nl();
	while (1)
	{

	}
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
	// int fd[3];
	// fd[0] = open("./files/1",O_RDONLY);
	// fd[1] = open("./files/2",O_RDONLY);
	// fd[2] = open("./files/3",O_RDONLY);
	// printf("|%s|\n",get_next_line(fd[0]));
	// printf("|%s|\n",get_next_line(fd[1]));
	// printf("|%s|\n",get_next_line(fd[2]));
	// printf("|%s|\n",get_next_line(fd[0]));
	// printf("|%s|\n",get_next_line(fd[1]));
	// printf("|%s|\n",get_next_line(fd[2]));
	// printf("|%s|\n",get_next_line(fd[0]));
	// printf("|%s|\n",get_next_line(fd[1]));
	// printf("|%s|\n",get_next_line(fd[2]));
	/*
		del을 안했을때 head가 가리키는곳 초기화
	*/
}