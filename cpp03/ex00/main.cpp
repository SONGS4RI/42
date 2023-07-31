/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 14:02:59 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

int main( void ) {
	ClapTrap A("A");
	// ClapTrap C;///////기본 생성자 막아놓음
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;

	// 1
	A.attack("wall");
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;
	// 2
	A.beRepaired(2);
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;
	// 3
	A.attack("wall");
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;
	// 4
	A.beRepaired(4);
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;
	// 5
	A.attack("wall");
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;
	// 6
	A.beRepaired(6);
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;
	// 7
	A.attack("wall");
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;
	// 8
	A.beRepaired(8);
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;
	// 9
	A.attack("wall");
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;
	// 10
	A.beRepaired(10);
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;
	// 11
	A.attack("wall");
	std::cout << "hit_point: " << A.getHitPoint() << ", energy_point: " << A.getEnergyPoint() << std::endl;


	ClapTrap B("B");
	std::cout << "hit_point: " << B.getHitPoint() << ", energy_point: " << B.getEnergyPoint() << std::endl;

	B.takeDamage(11);
	std::cout << "hit_point: " << B.getHitPoint() << ", energy_point: " << B.getEnergyPoint() << std::endl;

	B.beRepaired(11);
	std::cout << "hit_point: " << B.getHitPoint() << ", energy_point: " << B.getEnergyPoint() << std::endl;
	B.takeDamage(11);
	return 0;
}