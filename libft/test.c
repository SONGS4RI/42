/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:37:44 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/15 19:59:39 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len + 1)
		return (dstsize + src_len);
	if (dstsize > dst_len + 1)
	{
		while (src[i] != '\0' && dst_len + 1 + i < dstsize)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*mem;

	size = ft_strlen(s);
	mem = (char *)malloc(sizeof(char) * (size + 1));
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s, size + 1);
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*mem;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	mem = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s1, len_s1 + 1);
	ft_strlcat(mem, s2, (len_s1 + len_s2 + 1));
	return (mem);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
	{
		if (*tmp == c)
			return (tmp);
		tmp++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	find;
	int		i;

	last = (char *)s;
	find = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (last[i] == find)
			return (last + i);
		i--;
	}
	return (0);
}

size_t	ft_getstart(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

size_t	ft_getend(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (!ft_strchr(set, s1[len - i - 1]))
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*mem;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	if (start >= end) // 12321 12
		return (ft_strdup(""));
	mem = (char *)malloc(sizeof(char) * (end - start + 1));
	if (mem == NULL)
		return (NULL);
	ft_strlcpy(mem, s1 + start, end - start + 1);
	return (mem);
}

size_t	cnt_word(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
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

////////////////////////////////////////////////////////////////
int	main()
{
	char	str1[100] = "11 2 2 333   ";
	char	str2[100] = "12";

	printf("ft     : %zu\n",cnt_word(str1, ' '));
	// printf("ft     : %zu\n",ft_getend(str1, str2));
	// printf("origin : %s\n",ft_strlen(str1));

}