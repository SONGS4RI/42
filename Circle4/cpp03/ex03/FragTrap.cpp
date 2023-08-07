/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:30:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 17:06:18 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

void FragTrap::setHitPoint(unsigned int amount) {
	_frag_hit_point = amount;
}

void FragTrap::setEnergyPoint(unsigned int amount) {
	_frag_energy_point = amount;
}

void FragTrap::setAttackDamage(unsigned int amount) {
	_frag_attack_damage = amount;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "Constructor (FragTrap) called" << std::endl;

	_frag_hit_point = 100;
	_frag_energy_point = 100;
	_frag_attack_damage = 30;
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

const unsigned int& FragTrap::getHitPoint(void) const {
	return (_frag_hit_point);
}

const unsigned int& FragTrap::getEnergyPoint(void) const {
	return (_frag_energy_point);
}

const unsigned int& FragTrap::getAttackDamage(void) const {
	return (_frag_attack_damage);
}