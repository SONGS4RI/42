/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:27:59 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/22 14:19:44 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Wrong Usage: type ./convert [ num ]" << std::endl;
		return (1);
	}
	try {
		ScalarConverter::convert(argv[1]);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}