/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 14:41:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

int main( void ) {
	ClapTrap A("A");
	ScavTrap B("B");
	FragTrap C("C");
	FragTrap D = C;

	std::cout << A.getName() << " " << A.getHitPoint() << " " << A.getEnergyPoint() << " " << A.getAttackDamage() << std::endl;
	std::cout << B.getName() << " " << B.getHitPoint() << " " << B.getEnergyPoint() << " " << B.getAttackDamage() << std::endl;
	std::cout << C.getName() << " " << C.getHitPoint() << " " << C.getEnergyPoint() << " " << C.getAttackDamage() << std::endl;
	std::cout << D.getName() << " " << D.getHitPoint() << " " << D.getEnergyPoint() << " " << D.getAttackDamage() << std::endl;

	A.attack("wall");
	B.attack("wall");

	B.guardGate();
	C.highFivesGuys();
	return 0;
}