/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 17:23:40 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

int main( void ) {
	DiamondTrap D("D");

	std::cout << D.getName() << " " << D.ClapTrap::getHitPoint() << " "
	<< D.ClapTrap::getEnergyPoint() << " " << D.ClapTrap::getAttackDamage() << std::endl;

	std::cout << D.ClapTrap::getName() << std::endl;
	D.guardGate();
	D.highFivesGuys();

	return 0;
}