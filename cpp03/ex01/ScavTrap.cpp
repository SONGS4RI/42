/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:47:50 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/26 20:14:51 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

// ScavTrap::ScavTrap() : ClapTrap() {
// 	std::cout << "Constructor (ScavTrap) called" << std::endl;

// 	setName("");
// 	setHitPoint(100);
// 	setEnergyPoint(50);
// 	setAttackDamage(20);
// }

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "Constructor (ScavTrap) called" << std::endl;

	setName(name);
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor (ScavTrap) called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
	std::cout << "Constructor (ScavTrap) called" << std::endl;

	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	std::cout << "Copy assignment (ScavTrap) operator called" << std::endl;
	if (this == &obj) {
		setName(obj.getName());
		setHitPoint(obj.getHitPoint());
		setEnergyPoint(obj.getEnergyPoint());
		setAttackDamage(obj.getAttackDamage());
	}
	return (*this);
}

