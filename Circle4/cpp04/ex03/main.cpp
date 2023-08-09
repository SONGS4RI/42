/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:45:48 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/09 17:06:29 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main() {

	// AMateria* tmp = new Ice();
	Character* a = new Character("a");

	Character* b = new Character(*a);
	
	std::cout << "name: " << b->getName() << "\n";
	
	delete b;
	return (0);
}