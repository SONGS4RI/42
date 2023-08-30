/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:27:02 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/30 14:21:11 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename Func>
void iter(T* address, unsigned int len, Func& func) {
	for (unsigned int i=0; i<len; i++) {
		func(address[i]);
	}
}

#endif
