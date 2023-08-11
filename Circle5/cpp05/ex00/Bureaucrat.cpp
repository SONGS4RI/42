/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:02:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 19:28:19 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Exception: Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Exception: Grade is too low");
}

Bureaucrat::Bureaucrat(std::string name) : _name(name) {
	std::cout << "Default constructor called " << "[Bureaucrat]" << std::endl;

	_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	std::cout << "Default constructor called " << "[Bureaucrat]" << std::endl;

	if (grade == 0) throw GradeTooHighException();
	else if (grade > 150) throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) {
	std::cout << "Copy constructor called " << "[Bureaucrat]" << std::endl;

	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	std::cout << "Copy assignment operator called " << "[Bureaucrat]" << std::endl;
	if (this != &obj) {
		const_cast<std::string&>(_name) = obj._name;
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
	if (_grade == 1) throw GradeTooHighException();

	_grade--;
}

void Bureaucrat::decreaseGrade(void) {
	if (_grade == 150) throw GradeTooLowException();

	_grade++;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";

	return (os);
}
