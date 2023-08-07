/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:19:33 by jahlee            #+#    #+#             */
/*   Updated: 2023/02/07 13:35:27 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BUFFER_SIZE 1024

char *backup_nl(char *s, int idx)
{
	char *res;
	int i;

	res = malloc(sizeof(char) * (idx + 2));
	for(i=0;i<=idx;i++)
		res[i] = s[i];
	res[i] = '\0';
	i = 0;
	while (s[idx])
	{
		s[i++] = s[idx];
		idx++;
	}
	if (!s[idx])
		s[i] = '\0';
	return (res);
}

char *is_nl(char *s)
{
	int	idx = -1;
	char * res;

	while (++idx)
	{
		if (s[idx] == '\n')
			break ;
	}
	if (s[idx] == '\0')
		return (NULL);
	res = backup_nl(s, idx);
	return (res);
}

char *gnl(int fd)
{
	static char	*backup;
	char		s[BUFFER_SIZE];
	char		*res;
	int			read_cnt;

	res = NULL;
	if (!backup)
	{
		backup = malloc(sizeof(char) * BUFFER_SIZE);
		backup[0] = '\0';
	}
	if (backup[0] != '\0')
		res = is_nl(backup);
	while (!res)
	{
		read_cnt = read(fd, s, BUFFER_SIZE);
		res = read_nl(s, backup);
		if (read_cnt < BUFFER_SIZE && !res)
			return (ft_strjoin(backup, res));
	}
	return (res);
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;

	fd = open("./test", O_RDONLY);
	printf("|%s|",gnl(fd));
}