/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:12:46 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/04 17:49:57 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "default constructor called " << "[WrongAnimal]" << std::endl;

	_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
	std::cout << "Copy constructor called " << "[WrongAnimal]" << std::endl;
	*this=obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
	std::cout << "Copy assignment operator called " << "[WrongAnimal]" << std::endl;
	if (this != &obj) {
		_type = obj.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor called " << "[WrongAnimal]" << std::endl;
}


const std::string& WrongAnimal::getType(void) const {
	return (_type);
}

void WrongAnimal::makeSound() const {
	std::cout << "@#$%^&*!!!" << std::endl;
}