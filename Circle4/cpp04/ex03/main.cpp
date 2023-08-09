/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:45:48 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/09 20:39:48 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// void leaks() {
// 	system("leaks ex03");
// }

int main() {
	// atexit(leaks);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// me->unequip(0);
	// me->unequip(1);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "======extra test 1=============" << std::endl;

	MateriaSource* new_src = new MateriaSource(*static_cast<MateriaSource*>(src));
	std::cout << "copied: " << new_src->getSource(0)->getType() << std::endl;
	std::cout << "copied: " << new_src->getSource(1)->getType() << std::endl;

	delete new_src;

	std::cout << "======extra test 2=============" << std::endl;

	AMateria* ice1 = new Ice();
	AMateria* ice2 = new Ice(*static_cast<Ice*>(ice1));
	std::cout << "ice2: " << ice2->getType() << std::endl;

	AMateria* Cure1 = new Cure();
	AMateria* Cure2 = new Cure(*static_cast<Cure*>(Cure1));
	std::cout << "Cure2: " << Cure2->getType() << std::endl;

	delete ice1;
	delete ice2;
	delete Cure1;
	delete Cure2;

	std::cout << "======extra test 3=============" << std::endl;
	ICharacter* new_me = new Character(*static_cast<Character*>(me));
	new_me->use(0, *bob);
	new_me->use(1, *bob);
	std::cout << "111\n";
	new_me->unequip(0);
	std::cout << "2222\n";
	new_me->unequip(1);

	delete bob;
	delete me;
	delete src;
	delete new_me;

	return 0;
}