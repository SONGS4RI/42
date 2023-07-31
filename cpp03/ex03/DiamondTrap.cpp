/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 17:09:59 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "Constructor (DiamondTrap) called" << std::endl;

	_new_name = name;
	setName(name + "_clap_name");
	ClapTrap::setHitPoint(FragTrap::getHitPoint());
	ClapTrap::setEnergyPoint(ScavTrap::getEnergyPoint());
	ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj) {
	std::cout << "Constructor (DiamondTrap) called" << std::endl;

	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	std::cout << "Copy assignment (DiamondTrap) operator called" << std::endl;
	if (this == &obj) {
		_new_name = obj.getName();
		setName(obj.ClapTrap::getName());
		ClapTrap::setHitPoint(obj.ClapTrap::getHitPoint());
		ClapTrap::setEnergyPoint(obj.ClapTrap::getEnergyPoint());
		ClapTrap::setAttackDamage(obj.ClapTrap::getAttackDamage());
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor (DiamondTrap) called" << std::endl;
}

const std::string& DiamondTrap::getName(void) const {
	return (_new_name);
}
