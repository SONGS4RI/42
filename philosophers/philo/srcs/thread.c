/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:50:15 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/14 18:38:24 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_action(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->forks[philo->left]);
	philo_print("has taken left fork", philo->id, info);
	if (info->number_of_philosophers > 1)
	{
		pthread_mutex_lock(&info->forks[philo->right]);
		philo_print("has taken right fork", philo->id, info);
		philo_print("is now eating", philo->id, info);
		philo->last_meal_time = get_current_time();
		philo->eat_cnt++;
		pass_time(info->time_to_eat, info);
		pthread_mutex_unlock(&info->forks[philo->right]);
		philo_print("has put down right fork", philo->id, info);
	}
	pthread_mutex_unlock(&info->forks[philo->left]);
	philo_print("has put down left fork", philo->id, info);
}

void	*thread_action(void *ptr)
{
	t_philo	*philo;
	t_info	*info;

	philo = ptr;
	info = philo->info;
	philo_print("has born", philo->id, info);
	if (philo->id % 2)
		usleep(1000);
	while (!info->finish)
	{
		philo_action(philo);
		if (info->number_of_times_each_philosopher_must_eat == philo->eat_cnt)
		{
			info->eating_done_cnt++;
			break ;
		}
		philo_print("is sleeping", philo->id, info);
		pass_time(info->time_to_sleep, info);
		philo_print("is thinking", philo->id, info);
	}
	return (NULL);
}

int	work_philo(t_philo *philo)
{
	int			i;
	t_info 		*info;

	info = philo->info;
	i = -1;
	while (++i < info->number_of_philosophers)
	{
		philo[i].last_meal_time = get_current_time();
		if (pthread_create(&philo[i].thread, NULL, thread_action, &philo[i]))
			return (1);
	}
	check_philo_finished(philo);
	i = -1;
	while (++i < info->number_of_philosophers)
		pthread_join(philo[i].thread, NULL);
	free(philo);
	return (0);
}

void	check_philo_finished(t_philo *philo)
{
	long long	current_time;
	int			i;
	t_info		*info;

	info = philo->info;
	while (!info->finish)
	{
		if (info->eating_done_cnt == info->number_of_philosophers)
			break ;
		i = -1;
		while (++i < info->number_of_philosophers)
		{
			current_time = get_current_time();
			if (current_time - philo[i].last_meal_time >= info->time_to_die)//////seg
			{
				printf("지난시간: %lld, 죽는시간: %d\n", philo[i].last_meal_time, info->time_to_die);///////
				philo_print("has died", philo->id, info);
				info->finish = 1;
				break ;
			}
		}
	}
}