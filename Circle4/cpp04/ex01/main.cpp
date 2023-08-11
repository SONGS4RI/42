/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 15:54:50 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void leaks() {
	system("leaks ex01");
}

int main( void ) {
	atexit(leaks);
	Animal* dog1 = new Dog();
	const Animal* cat1 = new Cat();


	const Animal* dog2 = new Dog(*static_cast<Dog*>(dog1));
	Animal dog3 = *dog2;

	delete dog1;//should not create a leak
	delete cat1;
	delete dog2;

	std::cout << "===========test1==============" << std::endl;

	int n = 10;
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

	std::cout << "===========test2==============" << std::endl;

	std::string my_ideas[100] = {"1", "2", "3", "4",};
	Dog* new_dog = new Dog(my_ideas);
	for (int i=0; i<100; i++) {
		std::string s = new_dog->getBrain().getIdeas()[i];
		if (s != "") std::cout << s << std::endl;
	}

	Dog* copied_dog = new Dog(*new_dog);
	for (int i=0; i<100; i++) {
		std::string s = copied_dog->getBrain().getIdeas()[i];
		if (s != "") std::cout << s << std::endl;
	}

	Cat* new_cat = new Cat(my_ideas);
	for (int i=0; i<100; i++) {
		std::string s = new_cat->getBrain().getIdeas()[i];
		if (s != "") std::cout << s << std::endl;
	}

	Cat* copied_cat = new Cat(*new_cat);
	for (int i=0; i<100; i++) {
		std::string s = copied_cat->getBrain().getIdeas()[i];
		if (s != "") std::cout << s << std::endl;
	}


	delete new_dog;
	delete copied_dog;
	delete new_cat;
	delete copied_cat;

	return 0;
}