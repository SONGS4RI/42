/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:24:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/17 15:14:35 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cmath>// nan
#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input) {
	double converted;
	if (input == "" || (!std::isdigit(input[0]) && input.size() > 1)) {
		converted = nan("");
	} else {
		
	}
	// ScalarConverter::convertToChar(input);
	// ScalarConverter::convertToInt(input);
	// ScalarConverter::convertToFloat(input);
	// ScalarConverter::convertToDouble(input);
}

// void ScalarConverter::convertToChar(std::string input) {
// 	double num = strtod(input.c_str(), NULL);
// 	std::cout << "char : " << num;
// 	// if (num >= 256 || num < 0) {
// 	// 	std::cout << "impossible" << std::endl;
// 	// } else if (isspace(c) || iscntrl(c) || isblank(c)) {
// 	// 	std::cout << "not displayable" << std::endl;
// 	// } else {
// 	// 	std::cout << static_cast<char>(c) << std::endl;
// 	// }
// }

// void ScalarConverter::convertToInt(std::string input) {
// 	std::cout << "int : " << atoi(input.c_str()) << std::endl;
// }

// void ScalarConverter::convertToFloat(std::string input) {
// 	std::cout << "float : " << atof(input.c_str()) << std::endl;
// }

// void ScalarConverter::convertToDouble(std::string input) {
// 	std::cout << "double: " << atof(input.c_str()) << std::endl;
// }

