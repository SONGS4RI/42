/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:27 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/21 13:24:09 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>////////////////////
size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	if (!s)
		return (0);
	while (s[cnt])
		cnt++;
	return (cnt);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize, size_t idx)
{
	int	i;

	i = 0;
	if (dstsize == 0)
		return (0);
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
	return (substr);
}

char	*is_nl_backup(char **str, int len, t_gnl_list *tmp)
{
	int		idx;
	char	*res;
	char	*backup;

	res = NULL;
	idx = 0;
	while ((*str)[idx])
	{
		if ((*str)[idx] == '\n')
			break ;
		idx++;
	}
	if (idx < len)
	{
		res = ft_substr(*str, 0, idx + 1);
		backup = ft_substr(*str, idx + 1, len);
		free(tmp->backup);
		tmp->backup = backup;
	}
	return (res);
}

char	*is_nl_line(char **str, int len, t_gnl_list *tmp)
{
	int		idx;
	char	*res;
	char	*backup;

	res = NULL;
	idx = 0;
	while ((*str)[idx])
	{
		if ((*str)[idx] == '\n')
			break ;
		idx++;
	}
	if (idx < len)
	{
		res = combine_all(tmp->backup, ft_substr(*str, 0, idx + 1));
		backup = ft_substr(*str, idx + 1, len);
	}
	else
		backup = combine_all(tmp->backup, ft_substr(*str, 0, len));
	tmp->backup = backup;
	return (res);
}
