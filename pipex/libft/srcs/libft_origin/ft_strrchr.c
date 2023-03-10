/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:29:18 by jahlee            #+#    #+#             */
/*   Updated: 2023/03/10 20:17:43 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
