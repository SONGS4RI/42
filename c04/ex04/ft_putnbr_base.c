/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:12:53 by user              #+#    #+#             */
/*   Updated: 2022/09/02 18:49:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void    func(int nbr, char *base, int num)
{
    int c;

    c = nbr%num;
    func(nbr/num, base, num);
    write(1,base[c],1);
}

void ft_putnbr_base(int nbr, char *base)
{
    int num;

    num = ft_strlen(base);
    if(check(base))
    {
        func(nbr, base, num);
    }
}
