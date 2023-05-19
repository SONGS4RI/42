/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:50:15 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/19 17:37:24 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_action(t_philo *philo)
{
	t_info		*info;

	info = philo->info;
	pthread_mutex_lock(&info->forks[philo->left]);
	if (philo_print("has taken left fork", philo, info, &info->forks[philo->left]))
		return (1);
	if (info->number_of_philosophers > 1)////고쳐야함
	{
		pthread_mutex_lock(&info->forks[philo->right]);
		if (philo_print("has taken right fork", philo, info, &info->forks[philo->right]) \
		|| philo_print("is now eating", philo, info, &info->forks[philo->right]))
		{
			pthread_mutex_unlock(&info->forks[philo->left]);
			return (1);
		}
		pthread_mutex_lock(&philo->last_meal_time_mutex);
		philo->last_meal_time = get_current_time();
		pthread_mutex_unlock(&philo->last_meal_time_mutex);
		pass_time(info->time_to_eat);
		pthread_mutex_lock(&info->eat_mutex);
		if (info->number_of_times_each_philosopher_must_eat == ++philo->eat_cnt)
			info->eating_done_cnt++;
		pthread_mutex_unlock(&info->eat_mutex);
		pthread_mutex_unlock(&info->forks[philo->right]);
	}
	pthread_mutex_unlock(&info->forks[philo->left]);
	return (0);
}

void	*thread_action(void *ptr)
{
	t_philo	*philo;
	t_info	*info;

	philo = ptr;
	info = philo->info;
	pthread_mutex_lock(&info->start);//동시 시작을 위한 조건
	philo->last_meal_time = info->start_time;
	pthread_mutex_lock(&info->ready_cnt_mutex);////////
	info->ready_cnt++;
	pthread_mutex_unlock(&info->ready_cnt_mutex);////////
	pthread_mutex_unlock(&info->start);//////////////////
	if (philo->id % 2)
		usleep(info->time_to_eat * 500);
	while (42)
	{
		pthread_mutex_lock(&info->finish_mutex);////////
		if (info->finish)
		{
			pthread_mutex_unlock(&info->finish_mutex);////////
			break ;
		}
		pthread_mutex_unlock(&info->finish_mutex);////////
		if (philo_action(philo))
			break ;
		if (philo_print("is sleeping", philo, info, NULL))
			break ;
		pass_time(info->time_to_sleep);
		if (philo_print("is thinking", philo, info, NULL))
			break ;
	}
	return (NULL);
}

int	work_philo(t_philo *philo)
{
	int			i;
	t_info 		*info;

	info = philo->info;
	i = -1;
	pthread_mutex_lock(&info->start);
	while (++i < info->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, thread_action, &philo[i]))
			return (1);
	}
	info->start_time = get_current_time();
	pthread_mutex_unlock(&info->start);
	while (42)
	{
		pthread_mutex_lock(&info->ready_cnt_mutex);////////
		if (info->ready_cnt == info->number_of_philosophers)
			break;
		pthread_mutex_unlock(&info->ready_cnt_mutex);
	}
	pthread_mutex_unlock(&info->ready_cnt_mutex);////////
	check_philo_finished(philo);
	i = -1;
	while (++i < info->number_of_philosophers)
		pthread_mutex_unlock(&info->forks[i]);
	i = -1;
	while (++i < info->number_of_philosophers)
		pthread_join(philo[i].thread, NULL);
	free_destroy_all(philo);
	return (0);
}

void	check_philo_finished(t_philo *philo)
{
	t_info		*info;

	info = philo->info;
	while (42)
	{
		usleep(500);
		pthread_mutex_lock(&info->finish_mutex);////////
		if (info->finish)
		{
			pthread_mutex_unlock(&info->finish_mutex);////////
			break ;
		}
		pthread_mutex_unlock(&info->finish_mutex);////////
		pthread_mutex_lock(&info->eat_mutex);////////
		if (info->eating_done_cnt == info->number_of_philosophers)
		{
			pthread_mutex_unlock(&info->eat_mutex);////////
			pthread_mutex_lock(&info->finish_mutex);////////
			info->finish = 1;
			pthread_mutex_unlock(&info->finish_mutex);////////
			return ;
		}
		pthread_mutex_unlock(&info->eat_mutex);////////
	}
}

int	philo_print(char *message, t_philo *philo, t_info *info, pthread_mutex_t *ptr)
{
	long long	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(&philo->last_meal_time_mutex);
	if (current_time - philo->last_meal_time >= info->time_to_die)
	{
		if (ptr)
			pthread_mutex_unlock(ptr);
		pthread_mutex_unlock(&philo->last_meal_time_mutex);
		pthread_mutex_lock(&info->finish_mutex);
		if (info->finish)
		{
			pthread_mutex_unlock(&info->finish_mutex);
			return (1);
		}
		info->finish = 1;
		pthread_mutex_unlock(&info->finish_mutex);
		printf("[%lld ms] %d has died\n", current_time - info->start_time, philo->id);
		return (1);
	}
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	pthread_mutex_lock(&info->finish_mutex);
	if (info->finish)
	{
		pthread_mutex_unlock(&info->finish_mutex);
		if (ptr)
			pthread_mutex_unlock(ptr);
		return (1);
	}
	pthread_mutex_unlock(&info->finish_mutex);
	printf("[%lld ms] %d %s\n", current_time - info->start_time, philo->id, message);
	return (0);
}