/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:23:02 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/07 19:25:22 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "default constructor called " << "[Ice]" << std::endl;
}

Ice::Ice(const Ice& obj) : AMateria(obj) {
	std::cout << "Copy constructor called " << "[Ice]" << std::endl;
	*this = obj;
}

Ice& Ice::operator=(const Ice& obj) {
	std::cout << "Copy assignment operator called " << "[Ice]" << std::endl;
	if (this != &obj) {
		setType(obj.getType());
	}
	return (*this);
}

Ice::~Ice() {
	std::cout << "Destructor called " << "[Ice]" << std::endl;
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

