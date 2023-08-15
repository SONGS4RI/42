/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:45:48 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 20:20:47 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Floor.hpp"

void leaks() {
	system("leaks $PPID");
}

// int main() {
// 	atexit(leaks);
// 	Floor* floor1 = Floor::getFloor();
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete floor1;
// 	delete src;
// 	delete me;
// 	delete bob;

// 	return 0;
// }



void    iMaterSourceTest(IMateriaSource& skillBook)
{
	std::cout << "[IMateriaSource test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "Filling skill book [ice][ice][ice][cure]" << std::endl;
	skillBook.learnMateria(new Ice());
	skillBook.learnMateria(new Ice());
	skillBook.learnMateria(new Ice());
	skillBook.learnMateria(new Cure());

	std::cout << "\n[Skill book's slot is full]" << std::endl;
	skillBook.learnMateria(new Ice());
}

void    equipTest(ICharacter& target, IMateriaSource& skillBook)
{
	std::cout << "\n[Equip test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	AMateria* tmp;
	tmp = skillBook.createMateria("ice");
	target.equip(tmp);
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);

	std::cout << "\nTesting equip equipped Materia pointer already" << std::endl;
	target.equip(tmp);
	target.equip(tmp);
	target.equip(tmp);
	target.equip(tmp);

	std::cout << "\nFilling character's inventory with created other Materia" << std::endl;
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);
	std::cout << "\nCharacter's inventory [ice][cure][cure][cure]" << std::endl;

	std::cout << "\n[Character's inventory slot is full]" << std::endl;
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);
}

void    useTest(ICharacter& target)
{
	std::cout << "\n[Use test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "\nTesting a character's use of a skill (material) in order" << std::endl;
	target.use(0, target);
	target.use(1, target);
	target.use(2, target);
	target.use(3, target);
}

void    unequipTest(ICharacter& target)
{
	std::cout << "\n[Unequip test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	target.unequip(0);
	target.use(0, target);
	target.use(1, target);
	target.use(2, target);
	target.use(3, target);

	target.unequip(3);
	target.use(0, target);
	target.use(1, target);
	target.use(2, target);
	target.use(3, target);
}

void    rangeTest(ICharacter& target)
{
	std::cout << "\n[range test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	target.unequip(4);
	target.unequip(-2147483648);
	target.use(4, target);
	target.use(-2147483648, target);
}

void    interactiveTest(ICharacter& target, IMateriaSource& skillBook)
{
	iMaterSourceTest(skillBook);
	equipTest(target, skillBook);
	useTest(target);
	unequipTest(target);
	rangeTest(target);
}

int main()
{
	atexit(leaks);
	Floor* floor1 = Floor::getFloor();
	Floor* floor2 = Floor::getFloor(); (void)floor2;
	Floor* floor3 = Floor::getFloor(); (void)floor3;

	IMateriaSource* skillBook = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* monster = new Character("monster");

	interactiveTest(*me, *skillBook);

	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->equip(skillBook->createMateria("ice"));
	me->equip(skillBook->createMateria("cure"));
	me->equip(skillBook->createMateria("ice"));
	me->equip(skillBook->createMateria("cure"));
	me->equip(skillBook->createMateria("ice"));
	me->equip(skillBook->createMateria("cure"));
	me->use(0, *monster);
	me->use(1, *monster);
	me->use(2, *monster);
	me->use(3, *monster);

	delete monster;
	delete me;
	delete skillBook;
	delete floor1;
	return 0;
}

