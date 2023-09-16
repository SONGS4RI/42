/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:41:40 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/16 17:18:24 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main() {
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Span sp = Span(25);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(-2);
		sp.addNumber(-1);
		// sp.addNumber(INT32_MAX);
		// sp.addNumber(INT32_MIN);

		std::vector<int> test;
		for (int i=30; i<=200; i+=10) test.push_back(i);
		sp.addNumbers<std::vector<int> >(test.begin(), test.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		// sp.addNumber(1);
		// sp.addNumbers<std::vector<int> >(test.begin(), test.end());
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}