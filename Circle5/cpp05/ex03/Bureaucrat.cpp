/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:02:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 14:58:48 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Exception [Bureaucrat]: Grade (1 ~ 150) is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Exception [Bureaucrat]: Grade (1 ~ 150) is too low");
}

Bureaucrat::Bureaucrat(std::string name) : _name(name) {
	std::cout << "Default constructor called " << "[Bureaucrat]" << std::endl;

	_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	std::cout << "Default constructor called " << "[Bureaucrat]" << std::endl;

	if (grade == 0) throw new GradeTooHighException();
	else if (grade > 150) throw new GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj.getName()) {
	std::cout << "Copy constructor called " << "[Bureaucrat]" << std::endl;

	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	std::cout << "Copy assignment operator called " << "[Bureaucrat]" << std::endl;
	if (this != &obj) {
		_grade = obj._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called " << "[Bureaucrat]" << std::endl;
}

const std::string& Bureaucrat::getName(void) const {
	return (_name);
}

const unsigned int& Bureaucrat::getGrade(void) const {
	return (_grade);
}

void Bureaucrat::increaseGrade(void) {
	if (_grade == 1) throw new GradeTooHighException();

	_grade--;
}

void Bureaucrat::decreaseGrade(void) {
	if (_grade == 150) throw new GradeTooLowException();

	_grade++;
}

void Bureaucrat::signForm(AForm& obj) {
	try {
		obj.beSigned(*this);
	} catch (const std::exception& e) {
		std::cout << _name << " couldn’t sign "
		<< obj.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed " << obj.getName() << std::endl;
}

void Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
	} catch (const std::exception* e) {
		std::cout << _name << " couldn’t execute "
		<< form.getName() << " because " << e->what() << std::endl;
		delete e;
		return ;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";

	return (os);
}
