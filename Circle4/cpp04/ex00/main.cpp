/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/04 17:59:35 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void leaks() {
	system("leaks ex00");
}

int main( void ) {
	// atexit(leaks);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();// meow~~!!가 나와야함
	j->makeSound();// bark~~!!가 나와야함
	meta->makeSound();// @#$%^&*!!!가 나와야함
	std::cout << "==========================" << std::endl;
	// 업캐스팅을 하면 베이스의 메모리 만큼만 접근하기 때문에 파생클래스에서 오버라이드가 의도한대로 되지 않는다.
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << meta2->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	meta2->makeSound();// @#$%^&*!!!가 나와야함
	wrong_cat->makeSound();// meow~~!!가 나와야함

	// delete meta;
	// delete i;
	// delete j;
	// delete meta2;
	// delete wrong_cat;
	return 0;
}