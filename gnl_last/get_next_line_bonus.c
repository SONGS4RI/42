/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/20 17:31:28 by jahlee           ###   ########.fr       */
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
	free(tmp->backup);
	free(tmp);
	// printf("list freed at %p\n",tmp);////////////////////////
	return (head);
}

t_gnl_list	*find_fd(t_gnl_list *tmp, int fd, t_gnl_list *head)
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

char	*combine_all(char *str1, char *str2)
{
	char	*res;
	int		len_1;
	int		len_2;

	len_1 = ft_strlen(str1);
	len_2 = ft_strlen(str2);
	res = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str1, len_1 + 1, 0);
	ft_strlcpy(res, str2, len_1 + len_2 + 1, len_1);
	if (str1)
	{
		free(str1);
		// printf("freed str1 at %p\n",str1);/////////////////////////
	}
	if (str2)
	{
		free(str2);
		// printf("freed str2 at %p\n",str2);/////////////////////////
	}
	return (res);
}

char	*read_line(t_gnl_list *tmp, t_gnl_list **pt, int fd)
{
	char	*line;
	char	*res;
	int		read_cnt;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	read_cnt = read(fd, line, BUFFER_SIZE);
	if (read_cnt <=0 && !tmp)
	{
		free(line);
		return (NULL);
	}
	line[read_cnt] = '\0';
	res = is_nl_line(&line, read_cnt, *pt);
	if (read_cnt < BUFFER_SIZE && !res)
	{
		res = ft_substr(tmp->backup, 0, ft_strlen(tmp->backup));
		del_gnl_list(tmp);
		*pt = NULL;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	t_gnl_list			*tmp;
	char				*res;

	if (fd < 0)
		return (NULL);
	if (!head)
			head = find_fd(head, fd, NULL);
	tmp = find_fd(head, fd, NULL);
	if (tmp->backup)
	{
		res = is_nl_backup(&tmp->backup, ft_strlen(tmp->backup), tmp);
		if (res)
			return (res);
	}
	while (1)
	{
		res = read_line(tmp, &tmp, fd);
		if (res || !tmp)
			return (res);
	}
	if (!tmp)
		head = NULL;
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
}