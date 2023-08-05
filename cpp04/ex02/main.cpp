/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/05 15:16:43 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void leaks() {
	system("leaks ex02");
}

int main( void ) {
	atexit(leaks);
	// Animal* test1 = new Animal();// Abstract class이기 때문에 인스턴스화 불가능
	Animal* test2 = new Dog();
	Animal* test3 = new Cat();

	test2->makeSound();
	test3->makeSound();

	delete test2;
	delete test3;
	return 0;
}