/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:06:07 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/23 19:16:21 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ph_error(char *message)
{
	printf("%s\n", message);
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

	(void) philo;
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

void	unlock_destroy_free_all(t_philo *philo)
{
	t_info	*info;
	int		i;

	info = philo->info;
	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_unlock(&info->forks_mutex[i]);
	pthread_mutex_unlock(&info->eat_mutex);
	pthread_mutex_unlock(&info->finish_mutex);
	pthread_mutex_unlock(&info->print_mutex);
	i = -1;
	pthread_mutex_destroy(&info->start_mutex);
	pthread_mutex_destroy(&info->finish_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	pthread_mutex_destroy(&info->print_mutex);
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&info->forks_mutex[i]);
	free(philo);
	free(info->forks_status);
	free(info->forks_mutex);
}

int	philo_print(char *message, t_philo *philo, t_info *info)
{
	if (is_dead_philo(philo, info) || is_done_eating(info))
		return (1);
	if (is_finished(info))
		return (1);
	pthread_mutex_lock(&info->print_mutex);
	printf("%lld %d %s\n", get_current_time() - info->start_time, \
	philo->id, message);
	pthread_mutex_unlock(&info->print_mutex);
	return (0);
}
