/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:04:53 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/07 19:37:37 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "default constructor called " << "[Cure]" << std::endl;
}

Cure::Cure(const Cure& obj) : AMateria(obj) {
	std::cout << "Copy constructor called " << "[Cure]" << std::endl;
	*this = obj;
}

Cure& Cure::operator=(const Cure& obj) {
	std::cout << "Copy assignment operator called " << "[Cure]" << std::endl;
	if (this != &obj) {
		setType(obj.getType());
	}
	return (*this);
}

Cure::~Cure() {
	std::cout << "Destructor called " << "[Cure]" << std::endl;
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}

