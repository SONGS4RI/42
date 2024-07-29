/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:21:03 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/11 17:27:54 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcmp(char c, char *s2)
{
	int	i;

	i = 0;
	while (*s2)
	{
		if (c == *s2)
			return (1);
		s2++;
	}
	return (0);
}

int	cnt_word(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (charset[cnt])
		cnt++;
	if (cnt == 0)
		return (1);
	cnt = 0;
	while (*str)
	{
		if (ft_strcmp(*str, charset))
			str++;
		else
		{
			cnt++;
			str++;
			while (!ft_strcmp(*str, charset))
				str++;
		}
	}
	return (cnt);
}

char	*ft_strcpy(char *s1, char *s2, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s2 + idx);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		offset;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (cnt_word(str, charset) + 1));
	if (res == NULL)
		return (0);
	while (*str)
	{
		offset = 0;
		if (ft_strcmp(*str, charset))
			str++;
		else
		{
			while (!ft_strcmp(*(str + offset), charset) && *(str + offset))
				offset++;
			res[i] = (char *)malloc(offset + 1);
			if (res[i] == NULL)
				return (0);
			str = ft_strcpy(res[i++], str, offset);
		}
	}
	res[i] = 0;
	return (res);
}
