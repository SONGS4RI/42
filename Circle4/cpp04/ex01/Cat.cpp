/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:16:43 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 20:37:51 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() {
    std::cout << "default constructor called " << "[Cat]" << std::endl;

    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const std::string ideas[100]) {
    std::cout << "default constructor called " << "[Cat]" << std::endl;

    _type = "Cat";
    _brain = new Brain(ideas);
}

Cat::Cat(const Cat& obj) {
    std::cout << "Copy constructor called " << "[Cat]" << std::endl;

    _brain = NULL;
    *this = obj;
}

Cat& Cat::operator=(const Cat& obj) {
    std::cout << "Copy assignment operator called " << "[Cat]" << std::endl;
    if (this != &obj) {
        _type = obj._type;
        if (_brain) delete _brain;
        _brain = new Brain(*obj._brain);
    }
    return (*this);
}

Cat::~Cat() {
    std::cout << "Destructor called " << "[Cat]" << std::endl;

    delete _brain;
	_brain = NULL;
}

void Cat::makeSound() const {
    std::cout << "meow~~!!" << std::endl;
}

const Brain& Cat::getBrain(void) {
    return (*_brain);
}