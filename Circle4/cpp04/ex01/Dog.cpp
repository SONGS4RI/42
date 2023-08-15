/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:09:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 20:38:13 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "default constructor called " << "[Dog] " << std::endl;

	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const std::string ideas[100]) : Animal() {
	std::cout << "default constructor called " << "[Dog] " << std::endl;

	_type = "Dog";
	_brain = new Brain(ideas);
}

Dog::Dog(const Dog& obj) : Animal(obj) {
	std::cout << "Copy constructor called " << "[Dog] " << std::endl;

	_brain = NULL;
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "Copy assignment operator called " << "[Dog] " << std::endl;
	if (this != &obj) {
		_type = obj._type;
        if (_brain) delete _brain;
		_brain = new Brain(*obj._brain);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Destructor called " << "[Dog] " << std::endl;

	delete _brain;
	_brain = NULL;
}

void Dog::makeSound() const {
    std::cout << "bark~~!!" << std::endl;
}

const Brain& Dog::getBrain(void) {
    return (*_brain);
}