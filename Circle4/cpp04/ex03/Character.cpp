/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:02:07 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 14:32:49 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

Character::Character(const std::string& name) {
	std::cout << "default constructor called " << "[Character]" << std::endl;

	_name = name;
	for (int i=0; i<4; i++) {
		_inventory[i] = NULL;
	}
	_floor = NULL;
}

Character::Character(const Character& obj) {
	std::cout << "Copy constructor called " << "[Character]" << std::endl;

	*this=obj;
}

Character& Character::operator=(const Character& obj) {
	std::cout << "Copy assignment operator called " << "[Character]" << std::endl;
	if (this != &obj) {
		_name = obj._name;
		for (int i=0; i<4; i++) {
			if (obj._inventory[i]) _inventory[i] = obj._inventory[i]->clone();
			else _inventory[i] = NULL;
		}
		Floor* obj_cur = obj._floor;
		Floor* prev = _floor;
		_floor = NULL;
		while (obj_cur) {
			Floor* copied = new Floor;
			copied->materia = obj_cur->materia->clone();
			copied->next = NULL;
			if (_floor == NULL) _floor = copied;
			else {
				prev->next = copied;
				prev = copied;
			}
			obj_cur = obj_cur->next;
		}
	}
	return (*this);
}

Character::~Character() {
	std::cout << "Destructor called " << "[Character]" << std::endl;

	for (int i=0; i<4; i++) {
		if (_inventory[i]) delete _inventory[i];
	}
	Floor* cur = _floor;
	Floor* del;
	while (cur) {
		del = cur;
		cur = cur->next;
		delete del->materia;
		delete del;
	}
}

const std::string& Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* m) {
	for (int i=0; i<4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL) return ;
	std::cout << _name << " unequiped " << _inventory[idx]->getType() << std::endl;
	Floor* unequiped = new Floor;
	unequiped->materia = _inventory[idx];
	unequiped->next = NULL;
	Floor* cur = _floor;
	while (cur && cur->next) {
		cur = cur->next;
	}
	if (cur == NULL) _floor = unequiped;
	else cur->next = unequiped;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) return ;
	if (_inventory[idx]) {
		_inventory[idx]->use(target);
	}
}
