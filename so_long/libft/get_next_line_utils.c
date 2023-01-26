/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:27 by jahlee            #+#    #+#             */
/*   Updated: 2023/01/26 15:32:42 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len_free(const char *s, char **free_s)
{
	size_t	cnt;

	if (free_s && *free_s)
	{
		free(*free_s);
		*free_s = NULL;
		return (0);
	}
	cnt = 0;
	if (!s)
		return (0);
	while (s[cnt])
		cnt++;
	return (cnt);
}

size_t	ft_gnlcpy(char *dst, char *src, size_t dstsize, size_t idx)
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

char	*ft_gnlstr(char *s, int start, size_t len, t_gnl_list **tmp)
{
	char	*substr;
	size_t	new_len;

	if (!s || s[0] == '\0')
		return (NULL);
	if ((int)ft_len_free(s, NULL) < start)
		return (NULL);
	new_len = ft_len_free(s + start, NULL);
	if (new_len < len)
		len = new_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
	{
		(*tmp)->eof = 1;
		return (NULL);
	}
	substr[0] = '\0';
	ft_gnlcpy(substr, s + start, len + 1, 0);
	if (substr[0] == '\0')
	{
		free(substr);
		return (NULL);
	}
	return (substr);
}

char	*is_nl_backup(char **str, int len, t_gnl_list *tmp)
{
	int		idx;
	char	*res;
	char	*backup;

	res = NULL;
	idx = tmp->no_nl_idx;
	while ((*str)[idx])
	{
		if ((*str)[idx] == '\n')
			break ;
		idx++;
	}
	tmp->no_nl_idx = idx;
	if (idx < len)
	{
		res = ft_gnlstr(*str, 0, idx + 1, &tmp);
		backup = ft_gnlstr(*str, idx + 1, len, &tmp);
		tmp->no_nl_idx = 0;
		free(tmp->backup);
		tmp->backup = backup;
	}
	if (tmp->eof)
		return ((char *)ft_len_free(NULL, &res));
	return (res);
}

char	*is_nl_line(char **str, int len, t_gnl_list **tmp, int idx)
{
	char	*res;
	char	*backup;

	res = NULL;
	while ((*str)[++idx])
	{
		if ((*str)[idx] == '\n')
			break ;
	}
	(*tmp)->no_nl_idx += idx;
	if (idx < len)
	{
		res = ft_gnlstr(*str, 0, idx + 1, tmp);
		res = combine_all(&(*tmp)->backup, &res, tmp);
		backup = ft_gnlstr(*str, idx + 1, len, tmp);
		(*tmp)->no_nl_idx = 0;
		free(*str);
	}
	else
		backup = combine_all(&(*tmp)->backup, str, tmp);
	(*tmp)->backup = backup;
	if ((*tmp)->eof)
		return ((char *)ft_len_free(NULL, &res));
	return (res);
}
