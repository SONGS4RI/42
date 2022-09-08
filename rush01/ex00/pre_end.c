/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:39:30 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 22:07:57 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./func.h"

int	get_chk(t_sky *bd, char *s)
{
	int		i;
	int		j;
	int		cnt;
	char	*str;

	cnt = 0;
	str = s;
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			bd->chk[++j] = str[i] - '0';
			cnt++;
		}
		else if ((str[i] >= '5' && str[i] <= '9') || str[i] == '0')
			return (0);
	}
	if (cnt == 16)
		return (1);
	else
		return (0);
}

void	print_error(void)
{
	write(1, "Error", 5);
	write(1, "\n", 1);
}
