/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/19 16:28:58 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

t_gnl_list	*find_fd(t_gnl_list *tmp, int fd, int read_cnt, t_gnl_list	*head)
{
	while (tmp)
	{
		if (tmp->fd_idx == fd)
			break ;
		head = tmp;
		tmp = tmp->next;
	}
	if (read_cnt > 0 && !tmp)
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

char	*is_nl_backup(char *str, int len, int read_cnt, t_gnl_list *tmp)
{
	int		idx;
	char	*res;
	char	*back_up;

	idx = -1;
	while (++idx < len && tmp->backup[idx])
	{
		if (tmp->backup[idx] == '\n')
			break ;
	}
	if (idx < len)
	{
		res = ft_substr(tmp->backup, 0, idx + 1);
		// printf("(is_nl_backup) res malloced at%p\n",res);//////////////
		back_up = ft_substr(tmp->backup, idx + 1, len);
		// printf("(is_nl_backup) back_up malloced at%p\n",back_up);//////////////
		ft_len_free(NULL, &tmp->backup);
		// printf("{in is_nl_backup}\n");/////////////////////////
		tmp->backup = comb_all(back_up, str, ft_len_free(back_up, NULL), read_cnt);
		// printf("(is_nl_backup) tmp->backup malloced at%p\n",tmp->backup);//////////////
		return (res);
	}
	return (NULL);
}

char	*is_nl_line(char *str, int len, t_gnl_list *tmp)
{
	int		idx;
	int		len_b;
	char	*res;
	char	*back_up;

	idx = -1;
	len_b = ft_len_free(tmp->backup, NULL);
	while (++idx < len && str[idx])
	{
		if (str[idx] == '\n')
			break ;
	}
	if (idx < len)
	{
		res = comb_all(tmp->backup, ft_substr(str, 0, idx + 1), len_b, idx + 1);
		// printf("(is_nl_line) res malloced at%p\n",res);//////////////
		back_up = ft_substr(str, idx + 1, len);
		ft_len_free(NULL, &str);
		tmp->backup = back_up;
		// printf("(is_nl_line) back_up malloced at%p\n",tmp->backup);//////////////
		return (res);
	}
	back_up = comb_all(tmp->backup, str, ft_len_free(tmp->backup, NULL), len);
	// printf("(is_nl_backup) back_up malloced at%p\n",back_up);//////////////
	tmp->backup = back_up;
	return (NULL);
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
	// printf("------------fd : %d-----------\n",fd);///////////
	while (1)
	{
		// printf("-------------------------------\n");//////////////////
		line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		// printf("line malloced at %p\n",line);//////////////////////////////
		read_cnt = read(fd, line, BUFFER_SIZE);
		if (read_cnt >= 0)
			line[read_cnt] = '\0';
		if (!head)
			head = find_fd(head, fd, read_cnt, NULL);
		tmp = find_fd(head, fd, read_cnt, NULL);
		if (!head)
			return ((char *)ft_len_free(NULL, &line));
		res = is_nl(tmp, line, read_cnt);
		if (read_cnt < BUFFER_SIZE && !res)
			head = del_gnl_list(tmp);
		if (res)
			return (res);
	}
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd[3];
// 	fd[0] = open("./files/nl",O_RDONLY);
// 	// fd[1] = open("./files/2",O_RDONLY);
// 	// fd[2] = open("./files/3",O_RDONLY);
// 	printf("|%s|\n",get_next_line(fd[0]));
// 	printf("|%s|\n",get_next_line(fd[0]));
// 	// printf("|%s|\n",get_next_line(fd[1]));
// 	// printf("|%s|\n",get_next_line(fd[2]));
// 	// printf("|%s|\n",get_next_line(fd[0]));
// 	// printf("|%s|\n",get_next_line(fd[1]));
// 	// printf("|%s|\n",get_next_line(fd[2]));
// 	// printf("|%s|\n",get_next_line(fd[0]));
// 	// printf("|%s|\n",get_next_line(fd[1]));
// 	// printf("|%s|\n",get_next_line(fd[2]));
// }