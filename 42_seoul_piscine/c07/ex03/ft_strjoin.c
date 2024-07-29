/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:13:17 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/10 17:00:14 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_mystrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_mystrcpy(int size, char **strs, char *sep, char *pt)
{
	int	i;
	int	j;

	i = 0;
	while (size--)
	{
		j = -1;
		while (strs[i][++j])
		{
			*pt = strs[i][j];
			pt++;
		}
		j = -1;
		if (size > 0)
		{
			while (sep[++j])
			{
				*pt = sep[j];
				pt++;
			}
		}
		i++;
	}
	*pt = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		cnt;
	int		i;
	char	*pt;

	cnt = 1;
	i = -1;
	while (++i < size)
		cnt += ft_mystrlen(strs[i]);
	if (size == 0)
	{
		pt = (char *)malloc(1);
		pt[0] = '\0';
	}
	else
	{
		pt = (char *)malloc(cnt + (ft_mystrlen(sep) * (size - 1)) + 1);
		if (pt == NULL)
			return (0);
		ft_mystrcpy(size, strs, sep, pt);
	}
	return (pt);
}
