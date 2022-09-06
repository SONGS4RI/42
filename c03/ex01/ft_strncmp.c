/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:36:57 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/03 10:30:33 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while ((*s1 || *s2) && idx < n)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			idx++;
		}
		else
			return (*s1 - *s2);
	}
	return (0);
}
