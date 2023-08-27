/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:42:22 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/27 16:41:38 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND__HPP
# define EASYFIND__HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int val) {
	typename T::iterator iter = std::find(container.begin(), container.end(), val);
	if (iter == container.end()) throw std::exception();
	return (iter);
}

#endif