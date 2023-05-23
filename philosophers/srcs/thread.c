/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:50:15 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/23 16:25:42 by jahlee           ###   ########.fr       */
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
		pthread_mutex_lock(&info->finish_mutex);
		info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
		pthread_mutex_unlock(&info->eat_mutex);
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

int	philo_print(char *message, t_philo *philo, t_info *info)
{
	long long	current_time;

	current_time = get_current_time();
	if (is_dead_philo(philo, info) || is_done_eating(info))
		return (1);
	if (is_finished(info))
		return (1);
	printf("%lld %d %s\n", current_time - info->start_time, philo->id, message);
	return (0);
}

int	start_eating(t_philo *philo, t_info *info)
{
	if (philo_print("is eating", philo, info))
		return (1);
	philo->last_meal_time = get_current_time();
	if (++philo->eat_cnt == info->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&info->eat_mutex);
		info->eating_done_cnt++;
		pthread_mutex_unlock(&info->eat_mutex);
	}
	if (pass_time(info->time_to_eat, philo))
		return (1);
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
			break;
		}
		pthread_mutex_unlock(&info->forks_mutex[philo->right]);
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
	pthread_mutex_lock(&info->start_mutex);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&info->start_mutex);
	if (philo->id % 2 == 0)
		pass_time(info->time_to_eat / 2, philo);
	while (42)
	{
		if (check_forks_status(philo, info))
			break ;
		if (philo_print("is sleeping", philo, info))
			break ;
		if (pass_time(info->time_to_sleep, philo))
			break ;
		if (philo_print("is thinking", philo, info))
			break ;
	}
	return (NULL);
}

int	work_philo(t_philo *philo)
{
	t_info	*info;
	int		i;

	info = philo->info;
	i = -1;
	pthread_mutex_lock(&info->start_mutex);
	while (++i < info->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, thread_action, &philo[i]))
			return (1);
	}
	info->start_time = get_current_time();
	pthread_mutex_unlock(&info->start_mutex);
	i = -1;
	while (++i < info->number_of_philosophers)
		pthread_join(philo[i].thread, NULL);
	return (0);
}
