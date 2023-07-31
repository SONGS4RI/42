/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 17:11:54 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"
#include "./DiamondTrap.hpp"

int main( void ) {
	// ClapTrap A("A");
	// ScavTrap B("B");
	// FragTrap C("C");
	DiamondTrap D("D");

	// std::cout << A.getName() << " " << A.getHitPoint() << " " << A.getEnergyPoint() << " " << A.getAttackDamage() << std::endl;
	// std::cout << B.getName() << " " << B.getHitPoint() << " " << B.getEnergyPoint() << " " << B.getAttackDamage() << std::endl;
	// std::cout << C.getName() << " " << C.getHitPoint() << " " << C.getEnergyPoint() << " " << C.getAttackDamage() << std::endl;
	std::cout << D.getName() << " " << D.ClapTrap::getHitPoint() << " "
	<< D.ClapTrap::getEnergyPoint() << " " << D.ClapTrap::getAttackDamage() << std::endl;
	
	std::cout << D.ClapTrap::getName() << std::endl;
	// A.attack("wall");
	// B.attack("wall");

	// B.guardGate();
	// C.highFivesGuys();

	
	return 0;
}