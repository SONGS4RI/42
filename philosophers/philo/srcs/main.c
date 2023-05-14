/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:13:48 by jahlee            #+#    #+#             */
/*   Updated: 2023/05/14 16:56:33 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;
	int		exit_status;

	if (argc != 5 && argc != 6)
		return (ph_print_error("input error\n", 3));
	exit_status = init_info(&info, argc, argv);
	if (exit_status)
		return (ph_print_error("wrong argv\n", exit_status));
	exit_status = init_info_mutex(&info);
	if (exit_status)
		return (ph_print_error("mutex init error\n", exit_status));
	exit_status = init_philo(&philo, &info);
	if (exit_status)
		return (ph_print_error("thread init error\n", exit_status));
	exit_status = work_philo(philo);
	if (exit_status)
		return (ph_print_error("thread init error\n", exit_status));
}