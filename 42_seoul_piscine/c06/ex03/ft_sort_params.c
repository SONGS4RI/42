/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:54:57 by jahlee            #+#    #+#             */
/*   Updated: 2022/09/06 22:04:48 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_str_cpy(char *s1, char *s2, int flag)
{
	int	i;

	if (flag == 0)
	{
		while (*s1)
		{
			write(1, s1, 1);
			s1++;
		}
		write(1, "\n", 1);
	}
	else if (flag == 1)
	{
		i = 0;
		while (s2[i])
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
}

int	ft_str_len_cmp(char *s1, char *s2, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (s1[i])
			i++;
		return (i);
	}
	else if (flag == 1)
	{
		while (s1[i] || s2[i])
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (s1[i] - s2[i]);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*temp;

	if (argc == 0)
		argc = 0;
	i = 0;
	while (++i < argc - 1)
	{
		if (ft_str_len_cmp(argv[i], argv[i + 1], 1) > 0)
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			i = 0;
		}
	}
	i = 0;
	while (++i < argc)
		ft_put_str_cpy(argv[i], argv[i], 0);
	return (0);
}
