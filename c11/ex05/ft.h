/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:04:05 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/12 19:04:23 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		atoi(char *str);
void	ft_putnbr(int nbr);
void	myplus(int a, int b);
void	myminus(int a, int b);
void	mydev(int a, int b);
void	mymul(int a, int b);
void	mymod(int a, int b);
int		op_idx(char *str);
#endif