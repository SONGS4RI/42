/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:24:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/16 20:34:46 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input) {
	ScalarConverter::convertToChar(input);
	ScalarConverter::convertToInt(input);
	ScalarConverter::convertToFloat(input);
	ScalarConverter::convertToDouble(input);
}

void ScalarConverter::convertToChar(std::string input) {
	if (input.size() != 1 && )
	std::strtod();
	// std::cout << "char : ";
	// if (c >= 256 || c < 0) {
	// 	std::cout << "impossible" << std::endl;
	// } else if (isspace(c) || iscntrl(c) || isblank(c)) {
	// 	std::cout << "not displayable" << std::endl;
	// } else {
	// 	std::cout << static_cast<char>(c) << std::endl;
	// }
}

void ScalarConverter::convertToInt(std::string input) {
	std::cout << "int : " << atoi(input.c_str()) << std::endl;
}

void ScalarConverter::convertToFloat(std::string input) {
	std::cout << "float : " << atof(input.c_str()) << std::endl;
}

void ScalarConverter::convertToDouble(std::string input) {
	std::cout << "double: " << atof(input.c_str()) << std::endl;
}

