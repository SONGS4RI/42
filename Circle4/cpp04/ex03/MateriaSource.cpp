/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:28:33 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/05 18:31:18 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {
	std::cout << "default constructor called " << "[MateriaSource]" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj) {
	std::cout << "Copy constructor called " << "[MateriaSource]" << std::endl;
	*this=obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
	std::cout << "Copy assignment operator called " << "[MateriaSource]" << std::endl;
	if (this != &obj) {
		
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	std::cout << "Destructor called " << "[MateriaSource]" << std::endl;
}

template <typename T>
T sum(T a, T b){
    return a + b;
}
