/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:06:07 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/25 15:01:39 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ph_error(char *message, t_info *info, t_philo *philo)
{
	printf("%s\n", message);
	if (info)
	{
		if (info->forks_status)
			free(info->forks_status);
		if (info->forks_mutex)
			free(info->forks_mutex);
	}
	if (philo)
		free(philo);
	return (1);
}

long long	get_current_time(void)
{
	struct timeval	mytime;
	long long		current_time;

	gettimeofday(&mytime, NULL);
	current_time = mytime.tv_sec * 1000 + mytime.tv_usec / 1000;
	return (current_time);
}

int	pass_time(long long wait_time, t_philo *philo)
{
	long long	start;
	long long	current_time;

	start = get_current_time();
	while (42)
	{
		current_time = get_current_time();
		if (current_time - start >= wait_time)
			return (0);
		if (is_dead_philo(philo, philo->info))
			return (1);
		usleep(500);
	}
}

void	unlock_destroy_all(t_philo *philo)
{
	t_info	*info;
	int		i;

	info = philo->info;
	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_unlock(&info->forks_mutex[i]);
	pthread_mutex_unlock(&info->print_mutex);
	pthread_mutex_unlock(&info->start_mutex);
	pthread_mutex_unlock(&info->finish_mutex);
	pthread_mutex_unlock(&info->eat_mutex);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&info->forks_mutex[i]);
	destroy_mutex(&info->print_mutex, &info->start_mutex, \
			&info->finish_mutex, &info->eat_mutex);
}

int	destroy_mutex(pthread_mutex_t *ptr1, pthread_mutex_t *ptr2, \
pthread_mutex_t *ptr3, pthread_mutex_t *ptr4)
{
	if (ptr1)
		pthread_mutex_destroy(ptr1);
	if (ptr2)
		pthread_mutex_destroy(ptr1);
	if (ptr3)
		pthread_mutex_destroy(ptr1);
	if (ptr4)
		pthread_mutex_destroy(ptr1);
	return (1);
}
