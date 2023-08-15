/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:35:10 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/14 19:58:51 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
					AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "Default constructor called " << "[PresidentialPardonForm]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj) {
	std::cout << "Copy constructor called " << "[PresidentialPardonForm]" << std::endl;

	*this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	std::cout << "Copy assignment operator called " << "[PresidentialPardonForm]" << std::endl;
	if (this != &obj) {
		_target = obj._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor called " << "[PresidentialPardonForm]" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	try {
		checkExecutable(executor);
	} catch (const std::exception* e) {
		throw (e);
	}

	std::cout << executor.getName() << " executed " << getName() << std::endl;
	std::cout << "[ "<< _target << " ] has been pardoned by Zaphod Beeblebrox" << std::endl;
}
