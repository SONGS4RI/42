/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:58:13 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/03 12:07:33 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_mystrlen(char *str)
{
	unsigned int	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	idx_dest;
	unsigned int	idx_src;

	dest_len = ft_mystrlen(dest);
	src_len = ft_mystrlen(src);
	idx_dest = dest_len;
	idx_src = 0;
	while (src[idx_src] && (idx_src + dest_len + 1) < size)
	{
		dest[idx_dest] = src[idx_src];
		idx_dest++;
		idx_src++;
	}
	dest[idx_dest] = '\0';
	if (dest_len < size)
		return (src_len + dest_len);
	else
		return (src_len + size);
}
