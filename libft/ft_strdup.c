/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:46:20 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/21 13:19:33 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
