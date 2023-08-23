/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:45:35 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/23 20:21:44 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void leaks() {
	system("leaks $PPID");
}

int main() {
	atexit(leaks);
	srand(static_cast<unsigned int>(time(NULL)));
	Base base;
	Base* test = base.generate();
	std::cout << "==================test1==================" << std::endl;
	base.identify(test);
	std::cout << "==================test2==================" << std::endl;
	base.identify(*test);

	delete test;
	return (0);
}