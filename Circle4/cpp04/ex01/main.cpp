/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/04 20:28:01 by jahlee           ###   ########.fr       */
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

	std::cout << "======================" << std::endl;

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

	return 0;
}