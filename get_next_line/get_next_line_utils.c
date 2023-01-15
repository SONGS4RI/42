/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:27 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/15 20:14:18 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

size_t	ft_strlcat(char *dst, const char *s, size_t s_len, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	if (dstsize < dst_len + 1)
		return (dstsize + s_len);
	if (dstsize > dst_len + 1)
	{
		while (dstsize > dst_len + 1 + i && i < s_len)
		{
			dst[dst_len + i] = s[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + s_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
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
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

int	is_nl(char *tmp, int read_cnt, t_gnl_list *head)
{
	int	idx;

	idx = 0;
	if (!head || read_cnt == -1)
		return (-1);
	while (tmp[idx])
	{
		if (tmp[idx] == '\n')
			return (idx + 1);
		idx++;
	}
	if (read_cnt < BUFFER_SIZE)
	{
		head->eof = 1;
		return (idx + 1);
	}
	head->backup = (char *)malloc(sizeof(char) * (idx + 1));
	if (!head->backup)
		return (-1);
	head->backup[0] = '\0';
	ft_strlcpy(head->backup, tmp, idx + 1);
	free(tmp);
	return (0);
}
