/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:49:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/23 21:05:35 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>

# define RESET		"\033[0m"
# define RED		"\033[1;91m"
# define YELLOW		"\033[1;93m"

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_philo_must_eat;
	long long		start_time;
	int				eating_done_cnt;
	int				finish;
	int				*forks_status;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	*forks_mutex;
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
int			pass_time(long long wait_time, t_philo *philo);
void		unlock_destroy_free_all(t_philo *philo);
int			philo_print(char *message, t_philo *philo, t_info *info);

// init.c
int			init_info(t_info *info, int argc, char **argv);
int			init_info_mutex(t_info *info);
int			init_philo(t_philo **philo, t_info *info);

// thread.c
int			start_eating(t_philo *philo, t_info *info);
void		*thread_action(void *ptr);
int			work_philo(t_philo *philo);

// check_status.c
int			is_finished(t_info *info);
int			is_done_eating(t_info *info);
int			is_dead_philo(t_philo *philo, t_info *info);
int			check_fork(t_philo *philo, t_info *info, int fork);

#endif