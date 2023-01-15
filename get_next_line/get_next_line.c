/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/15 20:39:26 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*del_gnl_list(t_gnl_list *tmp, int read_cnt)
{
	t_gnl_list	*previous;

	if (tmp)
	{
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
		if (read_cnt != -1)
			free(tmp);
		tmp = NULL;
	}
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
	while (1)
	{
		read_cnt = read(fd, next_line, BUFFER_SIZE);
		head = find_fd(head, fd, read_cnt);
		if (head)
			tmp = combine_all(head, next_line, read_cnt);
		idx = is_nl(tmp, read_cnt, head);
		if (idx == -1 || !head)
			return ((char *)del_gnl_list(head, read_cnt));
		if (idx > 0)
		{
			tmp = res_line(head, tmp, idx - 1);
			if (head->eof)
				head = del_gnl_list(head, read_cnt);
			return (tmp);
		}
	}
}
