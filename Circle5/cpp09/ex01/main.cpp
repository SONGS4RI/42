/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:02:03 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/01 16:03:17 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Wrong Usage: ./RPN [ inverted Polish mathematical expression ]" << std::endl;
		return (1);
	}
	try {
		std::cout << RPN::calcuateRPN(argv[1]) << std::endl;
	} catch (const char* e) {
		std::cout << e << std::endl;
	}
	return (0);
}