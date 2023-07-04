/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:51:58 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/04 14:24:16 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

const std::string& Weapon::getType() {
	const std::string& typeRef = _type;
	return (typeRef);
}

void Weapon::setType(std::string type) {
	this->_type = type;
}

Weapon::Weapon(std::string type) {
	setType(type);
	std::cout << "weapon [ " << type << " ] has created" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "weapon [ " << _type << " ] has destroyed" << std::endl;
}