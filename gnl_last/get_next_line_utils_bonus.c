/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:27 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/19 17:46:02 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*is_nl(char **str, int len, t_gnl_list *tmp)
{
	int		idx;
	char	*res;
	char	*backup;

	res = NULL;
	idx = 0;
	while (*str[idx])
	{
		if (*str[idx] == '\n')
			break ;
		idx++;
	}
	if (idx < len)//개행존재
	{
		res = ft_substr(*str, )
	}
	//버퍼에 붙인다.
	return (res);
}
