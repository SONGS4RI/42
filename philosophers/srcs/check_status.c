/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:24:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/23 20:38:56 by jahlee           ###   ########.fr       */
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
	if (info->eating_done_cnt == info->num_of_philo)
	{
		pthread_mutex_unlock(&info->eat_mutex);
		if (is_finished(info))
			return (1);
		pthread_mutex_lock(&info->finish_mutex);
		info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
		pthread_mutex_lock(&info->print_mutex);
		printf("eating done!!!\n");
		pthread_mutex_unlock(&info->print_mutex);
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
		pthread_mutex_lock(&info->print_mutex);
		printf("%lld %d died\n", current_time - info->start_time, philo->id);
		pthread_mutex_unlock(&info->print_mutex);
		return (1);
	}
	return (0);
}

int	check_left_fork(t_philo *philo, t_info *info)
{
	while (42)
	{
		if (is_dead_philo(philo, info))
			return (1);
		pthread_mutex_lock(&info->forks_mutex[philo->left]);
		if (info->forks_status[philo->left] == 0)
		{
			info->forks_status[philo->left] = 1;
			pthread_mutex_unlock(&info->forks_mutex[philo->left]);
			if (philo_print("has taken a fork", philo, info))
				return (1);
			break ;
		}
		pthread_mutex_unlock(&info->forks_mutex[philo->left]);
		usleep(500);
	}
	return (0);
}

int	check_right_fork(t_philo *philo, t_info *info)
{
	while (42)
	{
		if (is_dead_philo(philo, info))
			return (1);
		pthread_mutex_lock(&info->forks_mutex[philo->right]);
		if (info->forks_status[philo->right] == 0)
		{
			info->forks_status[philo->right] = 1;
			pthread_mutex_unlock(&info->forks_mutex[philo->right]);
			if (philo_print("has taken a fork", philo, info))
				return (1);
			break ;
		}
		pthread_mutex_unlock(&info->forks_mutex[philo->right]);
		usleep(500);
	}
	return (0);
}
