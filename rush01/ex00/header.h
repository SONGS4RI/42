/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:37:19 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 22:06:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "./func.h"

//# include "./init.c"
t_sky	zero_board(t_sky bd);
t_sky	init_board(t_sky bd);

//# include "./pre_end.c"
int		get_chk(t_sky *bd, char *s);
void	print_error(void);

//# include "./board.c"
void	board_board(t_sky bd, int n, int *flag);
t_sky	fill_board(t_sky *bd, int n, int *flag);
void	print_board(t_sky bd, int n);

#endif
