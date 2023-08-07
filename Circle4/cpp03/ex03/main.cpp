/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/07 15:25:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

int main( void ) {
	DiamondTrap D("D");

	std::cout << D.ClapTrap::getHitPoint() << " " << D.ClapTrap::getEnergyPoint()
	<< " " << D.ClapTrap::getAttackDamage() << std::endl;

	D.attack("wall");
	D.guardGate();
	D.highFivesGuys();
	D.whoAmI();

	return 0;
}