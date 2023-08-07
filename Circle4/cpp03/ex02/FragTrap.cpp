/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:30:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 14:40:57 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "Constructor (FragTrap) called" << std::endl;

	setName(name);
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
}

FragTrap::~FragTrap() {
	std::cout << "Destructor (FragTrap) called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
	std::cout << "Constructor (FragTrap) called" << std::endl;

	*this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	std::cout << "Copy assignment (FragTrap) operator called" << std::endl;
	if (this == &obj) {
		setName(obj.getName());
		setHitPoint(obj.getHitPoint());
		setEnergyPoint(obj.getEnergyPoint());
		setAttackDamage(obj.getAttackDamage());
	}
	return (*this);
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << getName() << " requests highfive!!" << std::endl;
}