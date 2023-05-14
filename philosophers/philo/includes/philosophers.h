/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:49:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/14 15:01:54 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>//gettimeofday
# include <unistd.h>//write, usleep
# include <stdio.h>//printf
# include <string.h>//memset
# include <stdlib.h>//malloc, free
# include <pthread.h>
/*pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock */

typedef struct s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t printable;
	pthread_mutex_t *forks;
}	t_info;

typedef struct s_philo
{
	t_info		*info;
	pthread_t	thread;
	int			id;
	int			left;
	int			right;
	int			eat_cnt;
	int			last_meal_time;
}	t_philo;

#endif