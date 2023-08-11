/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:21:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 19:30:19 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat A("A", 1);
		Bureaucrat B("B", 150);
		Bureaucrat C = A;

		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;

		std::cout << "======================" << std::endl;

		A.decreaseGrade();
		std::cout << A << std::endl;
		B.increaseGrade();
		std::cout << B << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}