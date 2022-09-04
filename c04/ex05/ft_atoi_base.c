/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:47:58 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/04 22:04:18 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen1(char *str)
{
    int cnt;

    cnt = 0;
    while(*str)
    {
        str++;
        cnt++;
    }
    return cnt;
}

int check1(char *str)
{
    int i;
    int j;

    i = 0;
    if(ft_strlen1(str)<=1)
        return 0;
    while(str[i])
    {
        j = i+1;
        if(str[i] == '+' || str[i] == '-')
            return 0;
		if((*str >= 9 && *str <= 13) || *str == ' ')
			return 0;
        while(str[j])
        {
            if(str[j]==str[i])
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int ft_atoi_base(char *str, char *base)// str -> base
{
	int	base_len;
	int str_len;
	int	res;
	int i;
	
	res = 0;
	str_len = ft_strlen1(str);
	base_len = ft_strlen1(base);
	if(check1(base))
    {
        while(*str)
		{
			i = 0;
			while(i < base_len)
			{
				if(*str == base[i])
				{
						res = res * base_len + i;
						break;
				}
				i++;
			}
			str++;
		}
		return res;
    }
	else
		return 0;
}
