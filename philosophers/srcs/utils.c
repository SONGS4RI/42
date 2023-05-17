/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:06:07 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/17 19:46:35 by jahlee           ###   ########.fr       */
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

void	pass_time(long long wait_time, t_info *info)
{
	long long	start;
	long long	current_time;

	start = get_current_time();
	while (!info->finish)
	{
		current_time = get_current_time();
		if (current_time - start >= wait_time)
			break ;
		usleep(10);
	}
}

void	philo_print(char *message, int id, t_info *info)
{
	long long	current_time;

	pthread_mutex_lock(&info->printable);//////
	current_time = get_current_time();
	if (!info->finish)
		printf("[%lld ms] %d %s\n", current_time - info->start_time, id, message);
	pthread_mutex_unlock(&info->printable);
}

void	free_destroy_all(t_philo *philo)
{
	int		i;
	t_info	*info;

	i = -1;
	info = philo->info;
	free(philo);
	free(info->forks);
	while (++i < info->number_of_philosophers)
	{
		pthread_mutex_destroy(info->forks);
		pthread_mutex_destroy(&info->printable);
	}
}