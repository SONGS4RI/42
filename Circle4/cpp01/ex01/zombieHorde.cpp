/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:10:29 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/05 17:58:13 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* zombieHorde = new Zombie[N];

	for (int i=0; i<N; i++) {
		std::cout << "set zombie" << i << " name as " << name << std::endl;
		zombieHorde[i].setZombieName(name);
	}
	return (zombieHorde);
}