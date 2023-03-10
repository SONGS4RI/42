/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:26:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/10 17:55:35 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_word(char const *s, char c, size_t cnt)
{
	char	tmp;

	while (*s)
	{
		if (*s == c)
			s++;
		else if (*s == '\'' || *s == '\"')
		{
			cnt++;
			s++;
			tmp = *s;
			while (*s && (*s != tmp))
				s++;
			s++;
		}
		else
		{
			cnt++;
			s++;
			while (*s && (*s != c))
				s++;
		}
	}
	return (cnt);
}

static char	*ft_mycpy(char *s1, char *s2, size_t offset)
{
	size_t	i;
	size_t	idx;

	i = 0;
	idx = 0;
	if (*s2 == '\'' || *s2 == '\"')
		idx++;
	while (i < offset)
	{
		s1[i] = s2[idx];
		i++;
		idx++;
	}
	s1[i] = '\0';
	if (*s2 == '\'' || *s2 == '\"')
		offset += 2;
	return (s2 + offset);
}

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = 0;
		i++;
	}
	free(tab);
	return (NULL);
}

static	size_t	exception_func(const char *s, char c)
{
	size_t	offset;

	offset = 1;
	while (*(s + offset) && (*(s + offset) != c))
		offset++;
	return (offset - 1);
}

char	**ft_pipex_split(char const *s, char c, size_t i)
{
	char	**res;
	size_t	offset;

	res = (char **)ft_calloc(sizeof(char *), (cnt_word(s, c, 0) + 1));
	if (!res || !s)
		return (NULL);
	while (*s)
	{
		offset = 0;
		if (*s == c)
			s++;
		else
		{
			while (*(s + offset) && (*(s + offset) != c))
				offset++;
			if (*s == '\'' || *s == '\"')
				offset = exception_func(s, *s);
			res[i] = (char *)malloc(sizeof(char) * (offset + 1));
			if (!res[i])
				return (ft_malloc_error(res));
			s = ft_mycpy(res[i++], (char *)s, offset);
		}
	}
	res[i] = 0;
	return (res);
}
