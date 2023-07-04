/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:24:34 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/04 15:17:25 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"

const std::string& HumanA::getName() {
	const std::string& nameRef = _name;
	return (nameRef);
}

void HumanA::setName(std::string name) {
	_name = name;
}

void HumanA::attack() {
	std::cout
	<< getName()
	<< " attacks with their "
	<< _weapon.getType()
	<< std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon) {
	setName(name);
	std::cout
	<< "HumanA [ "
	<< getName()
	<< " ] has created"
	<< std::endl;
}

HumanA::~HumanA() {
	std::cout
	<< "HumanA [ "
	<< getName()
	<< " ] has destroyed"
	<< std::endl;
}
