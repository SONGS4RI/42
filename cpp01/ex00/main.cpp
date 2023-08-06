/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:18:11 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/06 17:35:37 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

// void leaks(void) {
// 	system("leaks ex00");
// }

int main() {
	// atexit(leaks);
	Zombie *zombie = newZombie("jack");
	randomChump("daniel");
	zombie->announce();
	delete zombie;
}