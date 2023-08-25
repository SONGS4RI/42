/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:11:04 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/25 20:29:30 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T& a, T& b) {
	return (a < b ? a : b);
}

template <typename T>
T max(T& a, T& b) {
	return (a > b ? a : b);
}

#endif
