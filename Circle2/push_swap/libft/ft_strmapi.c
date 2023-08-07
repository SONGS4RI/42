/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:30:18 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/21 14:53:25 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*tmp;

	if (!s || !f)
		return (NULL);
	tmp = ft_strdup(s);
	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		tmp[i] = f(i, tmp[i]);
		i++;
	}
	return (tmp);
}
