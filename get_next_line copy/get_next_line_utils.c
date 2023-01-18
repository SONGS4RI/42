/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:27 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/18 21:50:35 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>///////////////////////////

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	if (!s)
		return (0);
	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize, size_t idx)
{
	int	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (idx + 1 < dstsize && src[i])
	{
		dst[idx] = src[i];
		idx++;
		i++;
	}
	dst[idx] = '\0';
	return (idx);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	new_len;

	if (!s || s[0] == '\0')
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (NULL);
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	ft_strlcpy(substr, s + start, len + 1, 0);
	if (substr[0] == '\0')
	{
		free(substr);
		return (NULL);
	}
	return (substr);
}

char	*combine_all(char *str1, char *str2, int len_1, int len_2)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str1, len_1 + 1, 0);
	ft_strlcpy(res, str2, len_1 + len_2 + 1, len_1);
	if (str1)
	{
		free(str1);
		printf("freed str1 at %p\n",str1);/////////////////////////
	}
	if (str2)
	{
		free(str2);
		printf("freed str2 at %p\n",str2);/////////////////////////
	}
	return (res);
}

char	*is_nl(t_gnl_list *tmp, char *line, int read_cnt)
{
	char	*res;

	res = NULL;
	if (tmp->backup)
		res = is_nl_backup(line, ft_strlen(tmp->backup), read_cnt, tmp);
	if (!res)
		res = is_nl_line(line, read_cnt, tmp);
	if (read_cnt < BUFFER_SIZE)
	{
		res = ft_substr(tmp->backup, 0, ft_strlen(tmp->backup));
		printf("(is_nl)res malloced at %p\n",res);////////////////////////////
		free(line);
		printf("(is_nl)freed line at %p\n",line);/////////////////////////
	}
	return (res);
}
