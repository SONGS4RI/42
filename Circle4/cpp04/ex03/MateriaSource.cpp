/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:28:33 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/07 16:25:12 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {
	std::cout << "default constructor called " << "[MateriaSource]" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj) {
	std::cout << "Copy constructor called " << "[MateriaSource]" << std::endl;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
	std::cout << "Copy assignment operator called " << "[MateriaSource]" << std::endl;
	if (this != &obj) {
		for (int i=0; i<4; i++) {
			AMateria* ptr = obj.getSources();
			// _sources[i] = (obj.getSources())[i].clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	std::cout << "Destructor called " << "[MateriaSource]" << std::endl;
}

void MateriaSource::learnMateria(AMateria* obj) {
	for (int i=0; i<4; i++) {
		if (_sources[i] == NULL) {
			_sources[i] = obj->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i=0; i<4; i++) {
		if (_sources[i] && _sources[i]->getType() == type) {
			return (_sources[i]->clone());
		}
	}
	return (0);
}

const AMateria* MateriaSource::getSources() {
	return (*_sources);
}

