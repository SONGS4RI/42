/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:39:49 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/14 14:56:37 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Exception [AForm]: Grade (1 ~ 150) is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Exception [AForm]: Grade (1 ~ 150) is too low");
}

AForm::AForm(const std::string& name) : _name(name), _sign_grade(150), _execute_grade(150) {
	std::cout << "Default constructor called " << "[AForm]" << std::endl;

	_signature = false;
}

AForm::AForm(const std::string& name, const unsigned int& sign_grade,
const unsigned int& execute_grade) : _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade) {
	std::cout << "Default constructor called " << "[AForm]" << std::endl;

	if (sign_grade == 0 || execute_grade == 0) throw GradeTooHighException();
	else if (sign_grade > 150 || execute_grade > 150) throw GradeTooLowException();
	_signature = false;
}

AForm::AForm(const AForm& obj) : _name(obj._name), _sign_grade(obj._sign_grade), _execute_grade(obj._execute_grade) {
	std::cout << "Copy constructor called " << "[AForm]" << std::endl;

	*this = obj;
}

AForm& AForm::operator=(const AForm& obj) {
	std::cout << "Copy assignment operator called " << "[AForm]" << std::endl;
	if (this != &obj) {
		_signature = obj._signature;
	}
	return (*this);
}

AForm::~AForm() {
	std::cout << "Destructor called " << "[AForm]" << std::endl;
}

const std::string& AForm::getName(void) const {
	return (_name);
}
const bool& AForm::getSignature(void) const {
	return (_signature);
}
const unsigned int& AForm::getSignGrade(void) const {
	return (_sign_grade);
}
const unsigned int& AForm::getExecuteGrade(void) const {
	return (_execute_grade);
}

void AForm::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() > _sign_grade) throw GradeTooLowException();
	_signature = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "AForm [" << obj.getName() << "] ";
	if (obj.getSignature()) os << "is signed ";
	else os << "is not signed ";
	os << obj.getSignGrade() << " grade required to sign it, ";
	os << obj.getExecuteGrade() << " grade required to execute it";
	return (os);
}