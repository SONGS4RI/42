/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:10:34 by jahlee            #+#    #+#             */
/*   Updated: 2022/08/31 21:32:40 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				idx;
	unsigned int	i;

	i = 0;
	idx = ft_strlen(dest);
	while (*src && i < nb)
	{
		dest[idx] = *src;
		src++;
		idx++;
		i++;
	}
	dest[idx] = '\0';
	return (dest);
}
