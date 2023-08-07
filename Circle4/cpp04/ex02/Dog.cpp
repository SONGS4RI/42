/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:09:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/04 20:18:18 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "default constructor called " << "[Dog] " << std::endl;

	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj) {
	std::cout << "Copy constructor called " << "[Dog] " << std::endl;
	*this=obj;
}

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "Copy assignment operator called " << "[Dog] " << std::endl;
	if (this != &obj) {
		_type = obj.getType();
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Destructor called " << "[Dog] " << std::endl;

	delete _brain;
}

void Dog::makeSound() const {
    std::cout << "bark~~!!" << std::endl;
}

const Brain& Dog::getBrain(void) {
    return (*_brain);
}