/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:12:46 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/05 15:14:20 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal() {
	std::cout << "default constructor called " << "[Animal]" << std::endl;
}

Animal::Animal(const Animal& obj) {
	std::cout << "Copy constructor called " << "[Animal]" << std::endl;
	*this=obj;
}

Animal& Animal::operator=(const Animal& obj) {
	std::cout << "Copy assignment operator called " << "[Animal]" << std::endl;
	if (this != &obj) {
		_type = obj.getType();
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Destructor called " << "[Animal]" << std::endl;
}

const std::string& Animal::getType(void) const {
	return (_type);
}
