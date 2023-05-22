/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:49:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/22 20:19:16 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	long long		start_time;
	int				eating_done_cnt;
	int				*forks_status;
	int				finish;
	pthread_mutex_t finish_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t *forks_mutex;
}	t_info;

typedef struct s_philo
{
	t_info		*info;
	pthread_t	thread;
	int			id;
	int			left;
	int			right;
	int			eat_cnt;
	long long	last_meal_time;
}	t_philo;

// utils.c
int			ph_error(char *message);
long long	get_current_time(void);
void		pass_time(long long wait_time);
void		free_destroy_all(t_philo *philo);
// init.c
int			init_info(t_info *info, int argc, char **argv);
int			init_info_mutex(t_info *info);
int			init_philo(t_philo **philo, t_info *info);

// thread.c
int			check_forks_status(t_philo *philo, t_info *info);
void		*thread_action(void *ptr);
int			work_philo(t_philo *philo);
int			philo_print(char *message, t_philo *philo, t_info *info);
int			is_done_eating(t_info *info);
int			is_dead_philo(t_philo *philo, t_info *info);
int			start_eating(t_philo *philo, t_info *info);

#endif