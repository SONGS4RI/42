/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:50:15 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/22 20:38:48 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_done_eating(t_info *info)
{
	pthread_mutex_lock(&info->eat_mutex);
	if (info->eating_done_cnt == info->number_of_philosophers)
	{
		pthread_mutex_lock(&info->finish_mutex);
		info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
		pthread_mutex_unlock(&info->eat_mutex);
		printf("done eating\n");
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
		pthread_mutex_lock(&info->finish_mutex);
		info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
		printf("[%lld ms] %d has died\n", current_time - info->start_time, philo->id);
		return (1);
	}
	return (0);
}

int	philo_print(char *message, t_philo *philo, t_info *info)
{
	if (is_dead_philo(philo, info))
		return (1);
	if (is_done_eating(info))
		return (1);
	pthread_mutex_lock(&info->finish_mutex);
	if (info->finish)
	{
		pthread_mutex_unlock(&info->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&info->finish_mutex);
	printf("[%lld ms] %d %s\n", get_current_time() - info->start_time, philo->id, message);
	return (0);
}

int	start_eating(t_philo *philo, t_info *info)
{
	if (philo_print("has taken forks", philo, info))
		return (1);
	if (philo_print("has started eating", philo, info))
		return (1);
	philo->last_meal_time = get_current_time();

	pass_time(info->time_to_eat);
	if (++philo->eat_cnt == info->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&info->eat_mutex);
		info->eating_done_cnt++;
		pthread_mutex_unlock(&info->eat_mutex);
	}
	pthread_mutex_lock(&info->forks_mutex[philo->right]);
	info->forks_status[philo->right] = 0;
	pthread_mutex_unlock(&info->forks_mutex[philo->right]);
	pthread_mutex_lock(&info->forks_mutex[philo->left]);
	info->forks_status[philo->left] = 0;
	pthread_mutex_unlock(&info->forks_mutex[philo->left]);
	return (0);
}

int	check_forks_status(t_philo *philo, t_info *info)
{
	while (42)
	{
		pthread_mutex_lock(&info->forks_mutex[philo->left]);
		info->forks_status[philo->left] = 1;
		pthread_mutex_unlock(&info->forks_mutex[philo->left]);
		pthread_mutex_lock(&info->forks_mutex[philo->right]);
		if (!info->forks_status[philo->right])
		{
			info->forks_status[philo->right] = 1;
			pthread_mutex_unlock(&info->forks_mutex[philo->right]);
			break;
		}
		pthread_mutex_unlock(&info->forks_mutex[philo->right]);
		pthread_mutex_lock(&info->forks_mutex[philo->left]);
		info->forks_status[philo->left] = 0;
		pthread_mutex_unlock(&info->forks_mutex[philo->left]);
		usleep(500);
	}
	return (start_eating(philo, info));
}

void	*thread_action(void *ptr)
{
	t_philo	*philo;
	t_info	*info;

	philo = ptr;
	info = philo->info;
	if (philo->id % 2)
		usleep(info->time_to_eat * 500);
	while (42)
	{
		pthread_mutex_lock(&info->finish_mutex);
		if (info->finish)
		{
			pthread_mutex_unlock(&info->finish_mutex);
			break;
		}
		pthread_mutex_unlock(&info->finish_mutex);
		if (check_forks_status(philo, info))// 왼쪽 오른쪽 다들고 먹는거까지 끝
			break ;
		if (philo_print("is sleeping", philo, info))
			break;
		pass_time(info->time_to_sleep);
		if (philo_print("is thinking", philo, info))
			break;
		usleep(1000);
	}
	return (NULL);
}

int	work_philo(t_philo *philo)
{
	t_info	*info;
	int		i;

	info = philo->info;
	i = -1;
	info->start_time = get_current_time();
	while (++i < info->number_of_philosophers)
	{
		philo[i].last_meal_time = get_current_time();
		if (pthread_create(&philo[i].thread, NULL, thread_action, &philo[i]))
			return (1);
	}
	i = -1;
	while (++i < info->number_of_philosophers)
		pthread_join(philo[i].thread, NULL);
	return (0);
}
