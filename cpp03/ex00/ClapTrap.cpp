/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:54:33 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 14:03:00 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) {
	std::cout << "Parameter constructor called" << std::endl;

	_name = name;
	_hit_point = 10;
	_energy_point = 10;
	_attack_damage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) {
	std::cout << "Copy constructor called" << std::endl;

	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &obj) {
		_name = obj.getName();
		_hit_point = obj.getHitPoint();
		_energy_point = obj.getEnergyPoint();
		_attack_damage = obj.getAttackDamage();
	}
	return (*this);
}

const std::string& ClapTrap::getName(void) const {
	return (_name);
}

const unsigned int& ClapTrap::getHitPoint(void) const {
	return (_hit_point);
}

const unsigned int& ClapTrap::getEnergyPoint(void) const {
	return (_energy_point);
}

const unsigned int& ClapTrap::getAttackDamage(void) const {
	return (_attack_damage);
}

void ClapTrap::attack(const std::string& target) {
	if (_hit_point == 0 | _energy_point == 0) {
		std::cout << "ClapTrap " << _name << " can't attack" << std::endl;
		return ;
	}
	_energy_point--;

	std::cout << "ClapTrap " << _name << " attacks " << target
	<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hit_point == 0) {
		std::cout << "ClapTrap " << _name << " can't take damage" << std::endl;
		return ;
	}
	_hit_point = amount > _hit_point ? 0 : (_hit_point - amount);
	std::cout << "ClapTrap " << _name << " takes "
	<< amount << " points of damage!"<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hit_point == 0 | _energy_point == 0) {
		std::cout << "ClapTrap " << _name << " can't be repaired" << std::endl;
		return ;
	}
	_hit_point += amount;
	_energy_point--;

	std::cout << "ClapTrap " << _name << " repaired "
	<< amount << " hit_point!"<< std::endl;
}
