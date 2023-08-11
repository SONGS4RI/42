/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:39:49 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 20:25:57 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
	return ("Exception [Form]: Grade (1 ~ 150) is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Exception [Form]: Grade (1 ~ 150) is too low");
}

Form::Form(const std::string& name) : _name(name), _sign_grade(150), _execute_grade(150) {
	std::cout << "Default constructor called " << "[Form]" << std::endl;

	_signature = false;
}

Form::Form(const std::string& name, const unsigned int& sign_grade,
const unsigned int& execute_grade) : _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade) {
	std::cout << "Default constructor called " << "[Form]" << std::endl;

	if (sign_grade == 0 || execute_grade == 0) throw GradeTooHighException();
	else if (sign_grade > 150 || execute_grade > 150) throw GradeTooLowException();
	_signature = false;
}

Form::Form(const Form& obj) : _name(obj._name), _sign_grade(obj._sign_grade), _execute_grade(obj._execute_grade) {
	std::cout << "Copy constructor called " << "[Form]" << std::endl;

	*this = obj;
}

Form& Form::operator=(const Form& obj) {
	std::cout << "Copy assignment operator called " << "[Form]" << std::endl;
	if (this != &obj) {
		_signature = obj._signature;
	}
	return (*this);
}

Form::~Form() {
	std::cout << "Destructor called " << "[Form]" << std::endl;
}

const std::string& Form::getName(void) const {
	return (_name);
}
const bool& Form::getSignature(void) const {
	return (_signature);
}
const unsigned int& Form::getSignGrade(void) const {
	return (_sign_grade);
}
const unsigned int& Form::getExecuteGrade(void) const {
	return (_execute_grade);
}

void Form::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() > _sign_grade) throw GradeTooLowException();
	_signature = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << "Form [" << obj.getName() << "] ";
	if (obj.getSignature()) os << "is signed ";
	else os << "is not signed ";
	os << obj.getSignGrade() << " grade required to sign it, ";
	os << obj.getExecuteGrade() << " grade required to execute it";
	return (os);
}