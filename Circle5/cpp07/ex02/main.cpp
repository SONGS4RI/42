/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:43:50 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/25 21:02:19 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
int main() {
	try {
		Array<int> a;
		std::cout << "a.size(): " << a.size() << std::endl;
		Array<int> b(10);
		std::cout << "b.size(): " << b.size() << std::endl;
		for(int i=0; i<10; i++) b[i] = i;
		std::cout << "==========test b==========" << std::endl;
		for(int i=0; i<10; i++) std::cout << b[i] << " ";
		std::cout << std::endl;
		// std::cout << b[10] << std::endl;// exception!

		Array<char> c(10);
		std::cout << "c.size(): " << c.size() << std::endl;
		for(int i=0; i<10; i++) c[i] = i + 'a';
		std::cout << "==========test c==========" << std::endl;
		for(int i=0; i<10; i++) std::cout << c[i] << " ";
		std::cout << std::endl;

		Array<char> d(c);
		std::cout << "==========test c==========" << std::endl;
		for(int i=0; i<10; i++) std::cout << c[i] << " ";
		std::cout << std::endl;

		for(int i=0; i<10; i++) d[i] += 1;
			std::cout << "==========test d==========" << std::endl;
		for(int i=0; i<10; i++) std::cout << d[i] << " ";

		std::cout << std::endl;
		c = d;
			std::cout << "==========test c==========" << std::endl;
		for(int i=0; i<10; i++) std::cout << c[i] << " ";
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}