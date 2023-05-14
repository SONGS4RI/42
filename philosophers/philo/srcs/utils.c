/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:06:07 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/14 17:16:55 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int ph_print_error(char *message, int error)
{
	printf("%s\n", message);
	return (error);
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

	current_time = get_current_time();
	pthread_mutex_lock(&info->printable);
	if (!info->finish)
		printf("[%lld ms] %d %s\n", current_time - info->start_time, id + 1, message);
	pthread_mutex_unlock(&info->printable);
}

