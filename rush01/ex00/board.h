/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:32:32 by siwolee           #+#    #+#             */
/*   Updated: 2022/09/04 21:51:22 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

int	check_max_colup(t_sky bd);
int	check_max_coldown(t_sky bd);
int	check_max_rowleft(t_sky bd);
int	check_max_rowright(t_sky bd);
int	check_final(t_sky bd);

int	check_col_dup(t_sky bd);
int	check_row_dup(t_sky bd);
int	check_board(t_sky bd);

#endif
