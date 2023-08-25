/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:39:31 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/25 18:40:17 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

Array::Array() {
	std::cout << "Default constructor called " << "[Array]" << std::endl;
}

Array::Array(const Array& obj) {
	std::cout << "Copy constructor called " << "[Array]" << std::endl;

	*this = obj;
}

Array& Array::operator=(const Array& obj) {
	std::cout << "Copy assignment operator called " << "[Array]" << std::endl;
	if (this != &obj) {
		
	}
	return (*this);
}

Array::~Array() {
	std::cout << "Destructor called " << "[Array]" << std::endl;
}
