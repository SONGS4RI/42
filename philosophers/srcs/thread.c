/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:50:15 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/18 19:52:41 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_action(t_philo *philo)
{
	t_info		*info;

	info = philo->info;
	pthread_mutex_lock(&info->forks[philo->left]);
	philo_print("has taken left fork", philo->id, info);
	if (info->number_of_philosophers > 1)////고쳐야함
	{
		pthread_mutex_lock(&info->forks[philo->right]);
		philo_print("has taken right fork", philo->id, info);
		philo_print("is now eating", philo->id, info);
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
			break ;
		pthread_mutex_unlock(&info->finish_mutex);////////
		philo_action(philo);
		philo_print("is sleeping", philo->id, info);
		pass_time(info->time_to_sleep);
		philo_print("is thinking", philo->id, info);
	}
	pthread_mutex_unlock(&info->finish_mutex);////////
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
	check_philo_finished(philo);
	i = -1;
	while (++i < info->number_of_philosophers)
		pthread_join(philo[i].thread, NULL);
	free_destroy_all(philo);
	return (0);
}

void	check_philo_finished(t_philo *philo)
{
	// long long	current_time;
	int			i;
	t_info		*info;

	info = philo->info;

	while (42)
	{
		pthread_mutex_lock(&info->ready_cnt_mutex);////////
		if (info->ready_cnt == info->number_of_philosophers)
			break;
		pthread_mutex_unlock(&info->ready_cnt_mutex);
	}
	pthread_mutex_unlock(&info->ready_cnt_mutex);////////
	while (42)
	{
		usleep(500);
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
		i = -1;
		while (++i < info->number_of_philosophers)
		{
			pthread_mutex_lock(&philo[i].last_meal_time_mutex);
			if (get_current_time() - philo[i].last_meal_time >= info->time_to_die)
			{
				pthread_mutex_unlock(&philo[i].last_meal_time_mutex);
				// philo_print("had died", philo[i].id, info);
				pthread_mutex_lock(&info->finish_mutex);////////
				info->finish = 1;
				pthread_mutex_unlock(&info->finish_mutex);////////
				printf("%d has died\n",philo[i].id);
				return ;
			}
			pthread_mutex_unlock(&philo[i].last_meal_time_mutex);
		}
	}
}
