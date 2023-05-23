/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:05:02 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/23 16:05:52 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static int	ft_atoi(const char *str)
{
	int		sign;
	int		nbr;
	size_t	i;

	sign = 1;
	nbr = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + sign * (str[i] - '0');
		i++;
	}
	return (nbr);
}

int	init_info(t_info *info, int argc, char **argv)
{
	memset(info, 0, sizeof(t_info));
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (info->number_of_philosophers <= 0 || info->time_to_die < 0 || info->time_to_eat < 0 || info->time_to_sleep < 0)
		return (1);
	if (argc == 6)
	{
		info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		if (info->number_of_times_each_philosopher_must_eat <= 0)
			return (1);
	}
	info->forks_status = (int *)malloc(sizeof(int) * info->number_of_philosophers);
	if (!info->forks_status)
		return (1);
	memset(info->forks_status, 0, sizeof(int)*info->number_of_philosophers);
	return (0);
}

int	init_info_mutex(t_info *info)
{
	static int	i = -1;

	if (pthread_mutex_init(&info->eat_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&info->finish_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&info->start_mutex, NULL))
		return (1);
	info->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->number_of_philosophers);
	if (!info->forks_mutex)
		return (1);
	while (++i < info->number_of_philosophers)
	{
		if (pthread_mutex_init(&info->forks_mutex[i], NULL))
			return (1);
	}
	return (0);
}

int	init_philo(t_philo **philo, t_info *info)
{
	static int	i = -1;

	*philo = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philosophers);
	if (!philo)
		return (1);
	while (++i < info->number_of_philosophers)
	{
		(*philo)[i].info = info;
		(*philo)[i].id = i + 1;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->number_of_philosophers;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].last_meal_time = 0;
	}
	return (0);
}