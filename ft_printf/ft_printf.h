/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:31:27 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/25 21:20:10 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf_c(char c);
int	ft_printf_s(char *str);
int	ft_printf_di(int nbr);
int	ft_printf_u(unsigned int nbr);
int	ft_printf_p(void *ptr);
int	ft_printf_hex(unsigned int nbr, const char type);
int	ft_printf_u(unsigned int nbr);
#endif