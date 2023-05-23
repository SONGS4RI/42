/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:06:07 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/23 16:28:52 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ph_error(char *message)
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
		usleep(1000);
	}
}

void	free_destroy_all(t_philo *philo)
{
	int		i;
	t_info	*info;

	i = -1;
	info = philo->info;
	pthread_mutex_destroy(&info->eat_mutex);
	pthread_mutex_destroy(&info->finish_mutex);
	while (++i < info->number_of_philosophers)
	{
		pthread_mutex_destroy(&info->forks_mutex[i]);
	}
	free(philo);
	free(info->forks_status);
	free(info->forks_mutex);
}
