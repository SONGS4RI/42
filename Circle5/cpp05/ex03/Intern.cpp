/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:37:14 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 16:16:09 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const char* Intern::WrongFormException::what(void) const throw() {
	return ("Exception [Intern]: Worng Form");
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
	std::string form_name[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	int i = 0;
	for (; i<3; i++) {
		if (form == form_name[i]) break;
	}
	switch (i)
	{
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			throw new WrongFormException();
	}
}
