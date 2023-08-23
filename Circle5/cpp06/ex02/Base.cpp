/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:33:00 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/23 20:21:38 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {

}

Base* Base::generate(void) {
	int idx = std::rand() % 3;
	switch (idx) {
		case 0:
			std::cout << "A created" << std::endl;
			return new A();
		case 1:
			std::cout << "B created" << std::endl;
			return new B();
		default:
			std::cout << "C created" << std::endl;
			return new C();
	}
}

void Base::identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "type: A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "type: B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "type: C" << std::endl;
		return ;
	}
}

void Base::identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "type: A" << std::endl;
	} catch (std::exception& e) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "type: B" << std::endl;
	} catch (std::exception& e) {
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "type: C" << std::endl;
	} catch (std::exception& e) {
	}
}
