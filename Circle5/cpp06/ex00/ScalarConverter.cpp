/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:24:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/16 19:22:43 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input) {

	double num = atof(input.c_str());
	std::cout << "char : " << static_cast<char>(num) << std::endl;
	std::cout << "int : " << static_cast<int>(num) << std::endl;
	std::cout << "float : " << static_cast<float>(num) << std::endl;
	std::cout << "double: " << num << std::endl;
}

char ScalarConverter::convertToChar(std::string input) {
	
}

int ScalarConverter::convertToInt(std::string input) {
	
}

float ScalarConverter::convertToFloat(std::string input) {
	
}

double ScalarConverter::convertToDouble(std::string input) {
	
}

