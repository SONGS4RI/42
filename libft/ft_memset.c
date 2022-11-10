/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:35:19 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/10 15:21:23 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char	*temp;
	
	temp = (unsigned char *)b;
	i = 0;
	while (i < len)
		temp[i++] = (unsigned char)c;
	return (temp);
}