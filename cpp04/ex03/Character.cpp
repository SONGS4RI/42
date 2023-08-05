/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:02:07 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/05 17:14:12 by jahlee           ###   ########.fr       */
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

}

void Character::unequip(int idx) {

}

void Character::use(int idx, ICharacter& target) {

}

