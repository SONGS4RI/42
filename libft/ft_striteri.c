/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:57:40 by jahlee            #+#    #+#             */
/*   Updated: 2022/11/21 13:19:34 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		f(i, (s + i));
		i++;
	}	
}
