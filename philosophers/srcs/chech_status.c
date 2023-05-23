/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:24:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/23 17:25:12 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_finished(t_info *info)
{
	pthread_mutex_lock(&info->finish_mutex);
	if (info->finish)
	{
		pthread_mutex_unlock(&info->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&info->finish_mutex);
	return (0);
}

int	is_done_eating(t_info *info)
{
	pthread_mutex_lock(&info->eat_mutex);
	if (info->eating_done_cnt == info->number_of_philosophers)
	{
		pthread_mutex_unlock(&info->eat_mutex);
		if (is_finished(info))
			return (1);
		pthread_mutex_lock(&info->finish_mutex);
		info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
		printf("eating done!!!\n");/////
		return (1);
	}
	pthread_mutex_unlock(&info->eat_mutex);
	return (0);
}

int	is_dead_philo(t_philo *philo, t_info *info)
{
	long long	current_time;

	philo->info = info;
	current_time = get_current_time();
	if (current_time - philo->last_meal_time >= info->time_to_die)
	{
		if (is_finished(info))
			return (1);
		pthread_mutex_lock(&info->finish_mutex);
		info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
		printf("%lld %d died\n", current_time - info->start_time, philo->id);
		return (1);
	}
	return (0);
}