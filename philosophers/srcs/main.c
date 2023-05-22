/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:13:48 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/22 15:11:46 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void leaks()
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	// atexit(leaks);
	if (argc != 5 && argc != 6)
		return (ph_error("usage: num_of_philosophers time_to_die time_to_eat"
		" time_to_sleep [num_of_times_to_must_eat]\n"));
	if (init_info(&info, argc, argv))
		return (ph_error("wrong argv\n"));
	if (init_info_mutex(&info))
		return (ph_error("mutex init error\n"));
	if (init_philo(&philo, &info))
		return (ph_error("thread init error\n"));
	if (work_philo(philo))
		return (ph_error("thread init error\n"));
}