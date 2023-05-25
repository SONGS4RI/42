/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:50:15 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/25 15:15:37 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_eating(t_philo *philo, t_info *info)
{
	if (philo_print("is eating", philo, info))
		return (1);
	philo->last_meal_time = get_current_time();
	if (++philo->eat_cnt == info->num_of_philo_must_eat)
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

void	*thread_action(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	pthread_mutex_lock(&philo->info->start_mutex);
	if (is_finished(philo->info))
	{
		pthread_mutex_unlock(&philo->info->start_mutex);
		return (NULL);
	}
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->info->start_mutex);
	if (philo->id % 2 == 0)
		pass_time(philo->info->time_to_eat / 2, philo);
	while (42)
	{
		if (check_fork(philo, philo->info, philo->left) || \
		check_fork(philo, philo->info, philo->right) || \
		start_eating(philo, philo->info) || \
		philo_print("is sleeping", philo, philo->info) || \
		pass_time(philo->info->time_to_sleep, philo) || \
		philo_print("is thinking", philo, philo->info))
			break ;
	}
	return (NULL);
}

int	work_philo(t_info *info, t_philo *philo)
{
	int		i;

	i = -1;
	pthread_mutex_lock(&info->start_mutex);
	while (++i < info->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, thread_action, &philo[i]))
		{
			info->finish = 1;
			pthread_mutex_unlock(&info->start_mutex);
			while (--i >= 0)
				pthread_join(philo[i].thread, NULL);
			return (1);
		}
	}
	info->start_time = get_current_time();
	pthread_mutex_unlock(&info->start_mutex);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_join(philo[i].thread, NULL);
	unlock_destroy_all(philo);
	free(philo);
	free(info->forks_status);
	free(info->forks_mutex);
	return (0);
}

int	philo_print(char *message, t_philo *philo, t_info *info)
{
	if (is_dead_philo(philo, info) || is_done_eating(info))
		return (1);
	pthread_mutex_lock(&info->print_mutex);
	if (is_finished(info))
	{
		pthread_mutex_unlock(&info->print_mutex);
		return (1);
	}
	printf("%lld %d %s\n", get_current_time() - info->start_time, \
	philo->id, message);
	pthread_mutex_unlock(&info->print_mutex);
	return (0);
}
