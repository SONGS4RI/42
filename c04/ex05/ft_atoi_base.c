/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:47:58 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/04 22:01:07 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
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

int check(char *str)
{
    int i;
    int j;

    i = 0;
    if(ft_strlen(str)<=1)
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
	str_len = ft_strlen(str);
	base_len = ft_strlen(base);
	if(check(base))
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

int main()
{
	char str[] = "15e";
	char base[] = "0123456789abcdef";

	printf("%d",ft_atoi_base(str,base));	
}