/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:02:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 17:35:00 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "default constructor called " << "[Bureaucrat]" << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) {
	std::cout << "Copy constructor called " << "[Bureaucrat]" << std::endl;

	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	std::cout << "Copy assignment operator called " << "[Bureaucrat]" << std::endl;
	if (this != &obj) {
		
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called " << "[Bureaucrat]" << std::endl;
}
