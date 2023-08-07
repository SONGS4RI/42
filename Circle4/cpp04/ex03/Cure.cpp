/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:18:41 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/05 18:18:43 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure() {
	std::cout << "default constructor called " << "[Cure]" << std::endl;
}

Cure::Cure(const Cure& obj) {
	std::cout << "Copy constructor called " << "[Cure]" << std::endl;
	*this=obj;
}

Cure& Cure::operator=(const Cure& obj) {
	std::cout << "Copy assignment operator called " << "[Cure]" << std::endl;
	if (this != &obj) {
		
	}
	return (*this);
}

Cure::~Cure() {
	std::cout << "Destructor called " << "[Cure]" << std::endl;
}
