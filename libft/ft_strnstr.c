/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:01:22 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/14 11:11:52 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	haystack_len;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = strlen(needle);
	haystack_len = strlen(haystack);
	if (haystack_len < needle_len || len < needle_len)
		return (0);
	i = 0;
	while (*haystack && (i < len))
	{
		if (!ft_memcmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
        i++;
	}
	return (0);
}
