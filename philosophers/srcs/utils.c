/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:06:07 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/18 19:15:06 by jahlee           ###   ########.fr       */
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

void	pass_time(long long wait_time)
{
	long long	start;
	long long	current_time;

	start = get_current_time();
	while (42)
	{
		current_time = get_current_time();
		if (current_time - start >= wait_time)
			return ;
		usleep(10);
	}
}

void	philo_print(char *message, int id, t_info *info)
{
	long long	current_time;

	pthread_mutex_lock(&info->finish_mutex);////////
	current_time = get_current_time();
	if (!info->finish)
		printf("[%lld ms] %d %s\n", current_time - info->start_time, id, message);
	pthread_mutex_unlock(&info->finish_mutex);////////
}

void	free_destroy_all(t_philo *philo)
{
	int		i;
	t_info	*info;

	i = -1;
	info = philo->info;
	pthread_mutex_destroy(&info->ready_cnt_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	pthread_mutex_destroy(&info->start);
	pthread_mutex_destroy(&info->finish_mutex);
	while (++i < info->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo[i].last_meal_time_mutex);
		pthread_mutex_destroy(&info->forks[i]);
	}
	free(philo);
	free(info->forks);
}