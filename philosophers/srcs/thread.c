/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:50:15 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/23 20:39:32 by jahlee           ###   ########.fr       */
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
		if (check_left_fork(philo, info) || check_right_fork(philo, info))
			break ;
		if (start_eating(philo, info))
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
	while (++i < info->num_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, thread_action, &philo[i]))
			return (1);
	}
	info->start_time = get_current_time();
	pthread_mutex_unlock(&info->start_mutex);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_join(philo[i].thread, NULL);
	unlock_destroy_free_all(philo);
	return (0);
}
