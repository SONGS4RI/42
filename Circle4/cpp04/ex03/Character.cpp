/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:02:07 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/05 18:16:53 by jahlee           ###   ########.fr       */
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
}

Character::Character(const Character& obj) {
	std::cout << "Copy constructor called " << "[Character]" << std::endl;
	*this=obj;
}

Character& Character::operator=(const Character& obj) {
	std::cout << "Copy assignment operator called " << "[Character]" << std::endl;
	if (this != &obj) {
		_name = obj.getName();
	}
	return (*this);
}

Character::~Character() {
	std::cout << "Destructor called " << "[Character]" << std::endl;
	
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
	if (idx < 0 || idx >= 4) return ;
	
}

void Character::use(int idx, ICharacter& target) {

}

const AMateria* Character::getInventory() const {
	return (*_inventory);
}
