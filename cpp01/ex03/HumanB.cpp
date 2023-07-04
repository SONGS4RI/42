/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:09:42 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/04 15:31:17 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanB.hpp"

const std::string& HumanB::getName() {
	const std::string& nameRef = _name;
	return (nameRef);
}

void HumanB::setName(std::string name) {
	_name = name;
}

void HumanB::attack() {
	if (_weapon) {
		std::cout
		<< getName()
		<< " attacks with their "
		<< _weapon->getType()
		<< std::endl;
	} else {
		std::cout
		<< getName()
		<< " has no weapon"
		<< std::endl;
	}
}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

HumanB::HumanB(std::string name) {
	setName(name);
	_weapon = NULL;
	std::cout
	<< "HumanB [ "
	<< getName()
	<< " ] has created"
	<< std::endl;
}

HumanB::~HumanB() {
	std::cout
	<< "HumanB [ "
	<< getName()
	<< " ] has destroyed"
	<< std::endl;
}
