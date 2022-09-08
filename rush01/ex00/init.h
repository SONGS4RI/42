/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:37:19 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 22:05:31 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

//# include "./init4.c"
t_sky	init_up(t_sky bd, int col);
t_sky	init_down(t_sky bd, int col);
t_sky	init_left(t_sky bd, int row);
t_sky	init_right(t_sky bd, int row);

#endif
