/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:09:18 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/14 19:59:06 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
				AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Default constructor called " << "[RobotomyRequestForm]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj) {
	std::cout << "Copy constructor called " << "[RobotomyRequestForm]" << std::endl;

	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	std::cout << "Copy assignment operator called " << "[RobotomyRequestForm]" << std::endl;
	if (this != &obj) {
		_target = obj._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor called " << "[RobotomyRequestForm]" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	try {
		checkExecutable(executor);
	} catch (const std::exception* e) {
		throw (e);
	}

	std::cout << executor.getName() << " executed " << getName() << std::endl;
	std::cout << "* drilling noises *	";
	srand(static_cast<unsigned int>(time(NULL)));
	if (rand() % 2) {
		std::cout << "[ " << _target << " ] has been robotomized successfully" << std::endl;
	} else {
		std::cout << "[ " << _target << " ] has been failed robotomizing" << std::endl;
	}
}
