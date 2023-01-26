/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/26 15:32:31 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl_list	*del_gnl_list(t_gnl_list **tmp)
{
	t_gnl_list	*head;

	head = NULL;
	if ((*tmp)->previous)
	{
		(*tmp)->previous->next = (*tmp)->next;
		if ((*tmp)->next)
			(*tmp)->next->previous = (*tmp)->previous;
		head = (*tmp);
		while (head->previous)
			head = head->previous;
	}
	else if ((*tmp)->next)
	{
		(*tmp)->next->previous = NULL;
		head = (*tmp)->next;
	}
	if ((*tmp)->backup)
		free((*tmp)->backup);
	if ((*tmp)->backup)
		(*tmp)->backup = NULL;
	free((*tmp));
	(*tmp) = NULL;
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
		tmp->previous = NULL;
		tmp->next = NULL;
		tmp->backup = NULL;
		tmp->fd_idx = fd;
		tmp->no_nl_idx = 0;
		tmp->eof = 0;
		if (head)
		{
			head->next = tmp;
			tmp->previous = head;
		}
	}
	return (tmp);
}

char	*combine_all(char **str1, char **str2, t_gnl_list **tmp)
{
	char	*res;
	int		len_1;
	int		len_2;

	len_1 = ft_len_free(*str1, NULL);
	len_2 = ft_len_free(*str2, NULL);
	res = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!res)
	{
		(*tmp)->eof = 1;
		ft_len_free(NULL, str1);
		return ((char *)ft_len_free(NULL, str2));
	}
	ft_gnlcpy(res, *str1, len_1 + 1, 0);
	ft_gnlcpy(res, *str2, len_1 + len_2 + 1, len_1);
	ft_len_free(NULL, str1);
	ft_len_free(NULL, str2);
	return (res);
}

char	*read_line(t_gnl_list **tmp, int fd)
{
	char	*line;
	char	*res;
	int		read_cnt;

	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
	{
		(*tmp)->eof = 1;
		return (NULL);
	}
	read_cnt = read(fd, line, BUFFER_SIZE);
	if ((read_cnt == 0 && !(*tmp)->backup) || read_cnt == -1 || (*tmp)->eof)
	{
		(*tmp)->eof = 1;
		return ((char *)ft_len_free(NULL, &line));
	}
	line[read_cnt] = '\0';
	res = is_nl_line(&line, read_cnt, tmp, -1);
	if (read_cnt < BUFFER_SIZE && !res && (*tmp)->backup && !(*tmp)->eof)
	{
		res = ft_gnlstr((*tmp)->backup, 0, ft_len_free((*tmp)->backup, 0), tmp);
		(*tmp)->eof = 1;
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
	if (!head)
		return (NULL);
	tmp = find_fd(head, fd, NULL);
	res = NULL;
	if (tmp->backup)
		res = is_nl_backup(&tmp->backup, ft_len_free(tmp->backup, 0), tmp);
	while (1)
	{
		if (!res)
			res = read_line(&tmp, fd);
		if (tmp->eof || res)
		{
			if (tmp->eof)
				head = del_gnl_list(&tmp);
			return (res);
		}
	}
}
