/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:49:02 by jahlee            #+#    #+#             */
/*   Updated: 2022/08/31 15:11:37 by jahlee           ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	idx;

	idx = ft_strlen(dest);
	while (*src)
	{
		dest[idx] = *src;
		src++;
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
