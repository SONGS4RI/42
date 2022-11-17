/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:26:38 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/17 15:57:36 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	cnt_word(char const *s, char c)
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

static char	*ft_mycpy(char *s1, char *s2, size_t offset)
{
	size_t	i;

	i = 0;
	while (i < offset)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
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
	tab = 0;
	return (NULL);
}
void leaks()
{
	system("leaks ft_split");
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	offset;
	size_t	i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	printf("%lu\n",sizeof(res));///

	if (!res)
		return (NULL);
	while (*s)
	{
		offset = 0;
		if (*s == c)
			s++;
		else
		{
			while ((*(s + offset) != c) && *(s + offset))
				offset++;
			res[i] = (char *)malloc(sizeof(char) * (offset + 1));
			if (!res[i])
				return (ft_malloc_error(res));
			s = ft_mycpy(res[i++], (char *)s, offset);
		}
	}
	res[i] = 0;
	return (res);
}



int main()
{
	// atexit(leaks);
	char str[100] = "1 22 333 4444";
	char **tmp;
	size_t i;
	
	i=0;
	// tmp = ft_split(str, ' ');
	// for (int i=0; i<5; i++)
	// 	printf("%d : %s\n",i, tmp[i]);
	// while(tmp[i])
	// {
	// 	free(tmp[i]);
	// 	i++;
	// }
	// free(tmp);
	printf("%d",10 % 10);

}
