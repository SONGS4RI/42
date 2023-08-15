/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:15:40 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 20:23:04 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Floor.hpp"

Floor* Floor::_floor = NULL;

Floor::Floor() {
	std::cout << "Default constructor called " << "[Floor]" << std::endl;

	// 리스트 생성
	_list = new MateriaList;
	_list->materia = NULL;
	_list->next = NULL;
}

Floor::Floor(const Floor& obj) {
	std::cout << "Copy constructor called " << "[Floor]" << std::endl;

	*this = obj;
}

Floor& Floor::operator=(const Floor& obj) {
	std::cout << "Copy assignment operator called " << "[Floor]" << std::endl;
	if (this != &obj) {

	}
	return (*this);
}

Floor::~Floor() {
	std::cout << "Destructor called " << "[Floor]" << std::endl;

	MateriaList* cur = _list;
	MateriaList* target = NULL;
	while (cur) {
		target = cur;
		cur = cur->next;
		if (target->materia) delete target->materia;
		delete target;
	}
}

Floor* Floor::getFloor(void) {
	if (_floor) return (_floor);
	_floor = new Floor();
	return (_floor);
}

void Floor::addToList(AMateria* obj) {
	MateriaList* cur = _list;

	while (cur->materia) {
		if (cur->materia == obj) return ;
		cur = cur->next;
	}
	cur->materia = obj;
	cur->next = new MateriaList;
	cur->next->materia = NULL;
	cur->next->next = NULL;

	std::cout << obj->getType() << "is dropped to floor" << std::endl;
}