/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:18:11 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/03 20:44:55 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
	int n = 5;
	Zombie *zombies = zombieHorde(n, "Jack");
	for (int i=0; i<n; i++) {
		zombies[i].announce();
	}
	delete[] zombies;
}