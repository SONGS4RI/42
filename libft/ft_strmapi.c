/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:30:18 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/17 16:59:27 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*tmp;

	if (s == 0 || f == 0)
		return (NULL);
	tmp = ft_strdup(s);
	i = 0;
	while (tmp[i])
	{
		tmp[i] = f(i, tmp[i]);
		i++;
	}
	return (tmp);
}
