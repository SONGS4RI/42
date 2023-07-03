/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:55:30 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/03 20:31:21 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string Zombie::getName(void) const {
	return (this->_name);
}

void Zombie::setZombieName(std::string name) {
	this->_name = name;
}

Zombie::Zombie() {
	this->_name = "";
	std::cout << "zombie has created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "zombie " << _name << " has destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}