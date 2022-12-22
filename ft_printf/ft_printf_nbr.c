/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:26:41 by jahlee            #+#    #+#             */
/*   Updated: 2022/12/22 18:26:42 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf_nbr(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len);
}