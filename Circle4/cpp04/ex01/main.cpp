/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 19:09:58 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void leaks() {
	system("leaks $PPID");
}

int main( void ) {
	atexit(leaks);

	std::cout << "===========test1==============" << std::endl;
	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog();

	*dog2 = *dog1;
	Dog* dog3 = new Dog(*dog1);

	delete dog1;
	delete dog2;
	delete dog3;

	std::cout << "===========test2==============" << std::endl;

	int n = 5;
	Animal *animals[n];

	// create
	for (int i=0; i<n; i++) {
		if (i%2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}

	// delete
	for (int i=0; i<n; i++) delete animals[i];

	std::cout << "===========test3==============" << std::endl;

	std::string my_ideas[100] = {"1", "2", "3", "4",};
	Dog* new_dog = new Dog(my_ideas);
	for (int i=0; i<100; i++) {
		std::string s = new_dog->getBrain().getIdeas()[i];
		if (s != "") std::cout << s << std::endl;
	}

	Dog* copied_dog1 = new Dog(*new_dog);
	for (int i=0; i<100; i++) {
		std::string s = copied_dog1->getBrain().getIdeas()[i];
		if (s != "") std::cout << s << std::endl;
	}
	std::string new_ideas[100] = {"5", "6", "7", "8",};
	Dog* copied_dog2 = new Dog(new_ideas);
	*copied_dog1 = *copied_dog2;
	for (int i=0; i<100; i++) {
		std::string s = copied_dog1->getBrain().getIdeas()[i];
		if (s != "") std::cout << s << std::endl;
	}

	delete new_dog;
	delete copied_dog1;
	delete copied_dog2;

	std::cout << "===========test4==============" << std::endl;

	Cat* new_cat = new Cat(my_ideas);
	for (int i=0; i<100; i++) {
		std::string s = new_cat->getBrain().getIdeas()[i];
		if (s != "") std::cout << s << std::endl;
	}

	Cat* copied_cat1 = new Cat(*new_cat);
	for (int i=0; i<100; i++) {
		std::string s = copied_cat1->getBrain().getIdeas()[i];
		if (s != "") std::cout << s << std::endl;
	}

	Cat* copied_cat2 = new Cat(new_ideas);
	*copied_cat1 = *copied_cat2;
	for (int i=0; i<100; i++) {
		std::string s = copied_cat1->getBrain().getIdeas()[i];
		if (s != "") std::cout << s << std::endl;
	}

	delete new_cat;
	delete copied_cat1;
	delete copied_cat2;

	return 0;
}