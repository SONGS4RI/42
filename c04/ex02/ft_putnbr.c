/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:18:00 by user              #+#    #+#             */
/*   Updated: 2022/09/02 17:39:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    func(long long num)
{
    long long c; 
    
    c = num%10 + '0';
    
    if(num>0)
    {
        func(num/10);
        write(1,&c,1);
    }
    return;
}

void    ft_putnbr(int nb)
{
    long long num = (long long) nb;
    if(num < 0)
    {
        write(1,"-",1);
        num *= -1;
    }
    func(num);
}

int main()
{
    ft_putnbr(-2147483648);
}