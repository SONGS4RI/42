/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:10:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/03 20:54:59 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* zombieHorde = new Zombie[N];

	for (int i=0; i<N; i++) {
		std::string newName = name + std::to_string(i+1);
		std::cout << "set zombie name as " << newName << std::endl;
		zombieHorde[i].setZombieName(newName);
	}
	return (zombieHorde);
}