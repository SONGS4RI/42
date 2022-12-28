/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:26:41 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/28 15:28:15 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_di(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
