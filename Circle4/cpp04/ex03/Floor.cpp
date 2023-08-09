/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:34:22 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/09 17:18:29 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Floor.hpp"

Floor::Floor() {
	std::cout << "default constructor called " << "[Floor]" << std::endl;

	for (int i=0; i<8; i++) _materias[i] = NULL;
	_idx = 0;
}

Floor::Floor(const Floor& obj) {
	std::cout << "Copy constructor called " << "[Floor]" << std::endl;

	*this = obj;
}

Floor& Floor::operator=(const Floor& obj) {
	std::cout << "Copy assignment operator called " << "[Floor]" << std::endl;
	if (this != &obj) {
		_idx = obj._idx;
		for (unsigned int i=0; i<_idx; i++) {
			_materias[i] = obj._materias[i]->clone();
		}
	}
	return (*this);
}

Floor::~Floor() {
	std::cout << "Destructor called " << "[Floor]" << std::endl;

	for (unsigned int i=0; i<_idx; i++) delete _materias[i];
}

const AMateria* Floor::getMateria(int idx) const {
	if (idx < 0 || idx >= 8) return 0;
	return (_materias[idx]);
}

void Floor::setMaterias(AMateria *obj) {
	if (_idx > 8) return ;
	_materias[_idx++] = obj;
}