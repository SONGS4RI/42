/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:47:50 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/07 16:51:45 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

void ScavTrap::setHitPoint(unsigned int amount) {
	_scav_hit_point = amount;
}

void ScavTrap::setEnergyPoint(unsigned int amount) {
	_scav_energy_point = amount;
}

void ScavTrap::setAttackDamage(unsigned int amount) {
	_scav_attack_damage = amount;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "Constructor (ScavTrap) called" << std::endl;

	_scav_hit_point = 100;
	_scav_energy_point = 50;
	_scav_attack_damage = 20;
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
	if (this != &obj) {
		setName(obj.getName());
		setHitPoint(obj.getHitPoint());
		setEnergyPoint(obj.getEnergyPoint());
		setAttackDamage(obj.getAttackDamage());
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (getHitPoint() == 0 || getEnergyPoint() == 0) {
		std::cout << "ScavTrap " << getName() << " can't attack" << std::endl;
		return ;
	}
	setEnergyPoint(getEnergyPoint() - 1);

	std::cout << "ScavTrap " << getName() << " attacks " << target
	<< ", causing " << getAttackDamage() << " points of damage!" << std::endl;

}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode" << std::endl;
}

const unsigned int& ScavTrap::getHitPoint(void) const {
	return (_scav_hit_point);
}

const unsigned int& ScavTrap::getEnergyPoint(void) const {
	return (_scav_energy_point);
}

const unsigned int& ScavTrap::getAttackDamage(void) const {
	return (_scav_attack_damage);
}
