/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:16:43 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 20:36:38 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() {
    std::cout << "default constructor called " << "[Cat]" << std::endl;

    _type = "Cat";
}

Cat::Cat(const Cat& obj) {
    std::cout << "Copy constructor called " << "[Cat]" << std::endl;
    *this=obj;
}

Cat& Cat::operator=(const Cat& obj) {
    std::cout << "Copy assignment operator called " << "[Cat]" << std::endl;
    if (this != &obj) {
        _type = obj._type;
    }
    return (*this);
}

Cat::~Cat() {
    std::cout << "Destructor called " << "[Cat]" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow~~!!" << std::endl;
}