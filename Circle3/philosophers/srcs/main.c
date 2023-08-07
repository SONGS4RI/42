/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:13:48 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/25 15:20:41 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (ph_error("usage: num_of_philosophers time_to_die time_to_eat" \
		" time_to_sleep [num_of_times_to_must_eat]", NULL, NULL));
	if (init_info(&info, argc, argv))
		return (ph_error("init_info error: wrogn argv or malloc error", \
		&info, NULL));
	if (init_info_mutex(&info))
		return (ph_error("init_info_mutex error: pthread_mutex_init error", \
		&info, NULL));
	if (init_philo(&philo, &info))
		return (ph_error("init_philo error: malloc error", &info, NULL));
	if (work_philo(&info, philo))
	{
		unlock_destroy_all(philo);
		return (ph_error("work_philo: thread create error", &info, philo));
	}
}
