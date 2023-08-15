/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:37:14 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 14:45:54 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

const char* Intern::WrongFormException::what() const throw() {
	return ("Exception [Intern]: Wrong Form");
}
Intern::Intern() {
	std::cout << "Default constructor called " << "[Intern]" << std::endl;
}

Intern::Intern(const Intern& obj) {
	std::cout << "Copy constructor called " << "[Intern]" << std::endl;

	*this = obj;
}

Intern& Intern::operator=(const Intern& obj) {
	std::cout << "Copy assignment operator called " << "[Intern]" << std::endl;
	if (this != &obj) {
		
	}
	return (*this);
}

Intern::~Intern() {
	std::cout << "Destructor called " << "[Intern]" << std::endl;
}

AForm* Intern::makeForm(const std::string& form, const std::string& target) const {
	if (/* form 없는 형식이면 */) {
		
	}
}
