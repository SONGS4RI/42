/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 14:21:20 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"
int main( void ) {
	ClapTrap A("A");
	ScavTrap B("B");

	std::cout << A.getName() << " " << A.getHitPoint() << " " << A.getEnergyPoint() << " " << A.getAttackDamage() << std::endl;
	std::cout << B.getName() << " " << B.getHitPoint() << " " << B.getEnergyPoint() << " " << B.getAttackDamage() << std::endl;

	A.attack("wall");
	B.attack("wall");

	B.guardGate();
	return 0;
}