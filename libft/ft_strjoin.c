/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:16:55 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/15 15:39:07 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
