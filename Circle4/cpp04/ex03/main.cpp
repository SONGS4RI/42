/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:45:48 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 17:42:26 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void leaks() {
	system("leaks ex03");
}

int main() {
	atexit(leaks);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "======extra test 1=============" << std::endl;

	MateriaSource* new_src = new MateriaSource(*static_cast<MateriaSource*>(src));
	std::cout << "copied: " << new_src->getSource(0)->getType() << std::endl;
	std::cout << "copied: " << new_src->getSource(1)->getType() << std::endl;

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
	new_me->use(2, *bob);
	new_me->unequip(0);
	new_me->unequip(1);
	new_me->equip(new_src->createMateria("ice"));
	new_me->unequip(1);
	new_me->equip(new_src->createMateria("cure"));
	new_me->unequip(1);
	new_me->equip(new_src->createMateria("ice"));
	new_me->unequip(1);
	new_me->equip(new_src->createMateria("cure"));
	new_me->unequip(1);

	delete bob;
	delete me;
	delete src;
	delete new_me;
	delete new_src;

	return 0;
}

/*

void leak(void)
{
	system("leaks $PPID");
}

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

	// std::cout << "\nTesting equip equipped Materia pointer already" << std::endl;
	// target.equip(tmp);
	// target.equip(tmp);
	// target.equip(tmp);
	// target.equip(tmp);

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

class Floor
{
	public: Floor* getInstance(void)
	{
		if (_floor == NULL)
			_floor = new Floor();
		return (floor);
	}
}

int main()
{
	atexit(leak);
	Floor *floor = Floor::getInstance();
	Floor *floor1 = Floor::getInstance();
	Floor *floor2 = Floor::getInstance();

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
	me->use(0, *monster);
	me->use(1, *monster);
	me->use(2, *monster);
	me->use(3, *monster);

	delete monster;
	delete me;
	delete skillBook;

	return 0;
}

*/