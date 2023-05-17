/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:50:15 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/17 16:41:20 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// static int	check_died(t_philo *philo)////////
// {
// 	long long	current_time;
// 	t_info		*info;

// 	info = philo->info;
// 	current_time = get_current_time();
// 	if (current_time - philo->last_meal_time >= philo->info->time_to_die)
// 	{
// 		philo_print("has died", philo->id, info);
// 		info->finish = 1;
// 		return (1);
// 	}
// 	return (0);
// }

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
	}
	pthread_mutex_unlock(&info->forks[philo->left]);
}

void	*thread_action(void *ptr)
{
	t_philo	*philo;
	t_info	*info;

	philo = ptr;
	info = philo->info;
	if (philo->id % 2)
		usleep(1000);
	while (!info->finish)
	{
		philo_action(philo);
		if (info->number_of_times_each_philosopher_must_eat == philo->eat_cnt && \
		info->number_of_times_each_philosopher_must_eat != 0)
			info->eating_done_cnt++;
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
	// free(philo);
	i = -1;
	while (++i < info->number_of_philosophers)
	{
		pthread_mutex_destroy(info->forks);
		pthread_mutex_destroy(&info->printable);
	}
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
		{
			info->finish = 1;
			break ;
		}
		i = -1;
		while (++i < info->number_of_philosophers)
		{
			current_time = get_current_time();
			if (current_time - philo[i].last_meal_time >= info->time_to_die)
			{
				printf("[%lld ms] %d has died\n", current_time - info->start_time, philo[i].id);
				printf("last meal time: %lld\n",philo[i].last_meal_time - info->start_time);//////
				info->finish = 1;
				break ;
			}
		}
	}
}

/*

pthread_detach()// for(10) sleep(1) print

for(5초)
	sleep(1)

*/