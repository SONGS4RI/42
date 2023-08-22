/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:24:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/22 17:47:50 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <cctype>
#include "ScalarConverter.hpp"

std::string ScalarConverter::_input = "";

void ScalarConverter::convert(const std::string& input) {
	ScalarConverter::_input = input;
	EType type = checkFlows(detectType());
	switch (type) {
		case TYPE_CHAR:
			std::cout << "Type: Char" << std::endl;
			break;
		case TYPE_INT:
			std::cout << "Type: Int" << std::endl;
			break;
		case TYPE_FLOAT:
			std::cout << "Type: Float" << std::endl;
			break;
		case TYPE_DOUBLE:
			std::cout << "Type: Double" << std::endl;
			break;
		case TYPE_NAN:
			std::cout << "NaN" << std::endl;
			break;
		default:
			std::cout << "Input Flows" << std::endl;
			break;
	}
	std::cout << "char: ";
	try {
		std::cout << convertToChar(type);
	} catch (const std::string& e) {
		std::cout << e;
	}
	std::cout<< std::endl;

	std::cout << "int: ";
	try {
		std::cout << convertToInt(type);
	} catch (const std::string& e) {
		std::cout << e;
	}
	std::cout<< std::endl;

	std::cout << "float: ";
	try {
		std::cout << convertToFloat(type);
	} catch (const std::string& e) {
		std::cout << e;
	}
	std::cout<< std::endl;

	std::cout << "double: ";
	try {
		std::cout << convertToDouble(type);
	} catch (const std::string& e) {
		std::cout << e;
	}
	std::cout<< std::endl;
}

EType ScalarConverter::detectType() {
	int input_size = _input.size();
	double converted = std::strtod(_input.c_str(), NULL);
	if (std::abs(converted) == 1.0 / 0.0) {
		if (_input == "inff" || _input == "+inff" || _input == "-inff") return (TYPE_FLOAT);
		return (TYPE_DOUBLE);
	}
	if (input_size == 1 && !std::isdigit(_input[0])) return (TYPE_CHAR);
	int dot_idx = -1, f_idx = -1;
	for (int i=0; i<input_size; i++) {
		if (_input[i] == '.' && dot_idx == -1 && i != 0) {
			dot_idx = i;
		} else if (_input[i] == 'f' && i == input_size - 1) {
			f_idx = i;
		} else if (!std::isdigit(_input[i])) {
			return (TYPE_NAN);
		}
	}
	if (dot_idx == -1) {
		return (TYPE_INT);
	} else if (f_idx != -1) {
		return (TYPE_FLOAT);
	}
	return (TYPE_DOUBLE);
}

EType ScalarConverter::checkFlows(const EType& type) {
	switch (type) {
		case TYPE_CHAR:
			if (!isascii(std::stoi(_input))) return (TYPE_FLOWS);
			break;
		case TYPE_INT:
			if (static_cast<double>(std::stoi(_input)) != std::stod(_input)) return (TYPE_FLOWS);
			break;
		case TYPE_FLOAT:
			if (static_cast<double>(std::stof(_input)) != std::stod(_input)) return (TYPE_FLOWS);
			break;
		default:
			break;
	}
	return (type);
}

char ScalarConverter::convertToChar(const EType& type) {
	std::string impossible = "impossible";
	switch (type) {
		case TYPE_CHAR:
			return (_input[0]);
		case TYPE_INT: case TYPE_FLOAT: case TYPE_DOUBLE:
			if (checkFlows(TYPE_CHAR) == TYPE_FLOWS) throw (impossible);
			return (static_cast<char>(std::stoi(_input)));
		default:
			throw (impossible);
	}
}

int ScalarConverter::convertToInt(const EType& type) {
	std::string impossible = "impossible";
	switch (type) {
		case TYPE_CHAR:
			return (static_cast<const int>(_input[0]));
		case TYPE_INT: case TYPE_FLOAT: case TYPE_DOUBLE:
			if (checkFlows(TYPE_INT) == TYPE_FLOWS) throw (impossible);
			return (static_cast<int>(std::stoi(_input)));
		default:
			throw (impossible);
	}
}

float ScalarConverter::convertToFloat(const EType& type) {
	std::string impossible = "impossible";
	std::string not_a_number = "nanf";
	switch (type) {
		case TYPE_CHAR:
			return (static_cast<float>(_input[0]));
		case TYPE_INT: case TYPE_FLOAT: case TYPE_DOUBLE:
			if (checkFlows(TYPE_FLOAT) == TYPE_FLOWS) throw (impossible);
			return (static_cast<float>(std::stof(_input)));
		case TYPE_NAN:
			throw (not_a_number);
		default:
			throw (impossible);
	}
}

double ScalarConverter::convertToDouble(const EType& type) {
	std::string impossible = "impossible";
	std::string not_a_number = "nan";
	switch (type) {
		case TYPE_CHAR:
			return (static_cast<double>(_input[0]));
		case TYPE_INT: case TYPE_FLOAT: case TYPE_DOUBLE:
			return (static_cast<double>(std::stod(_input)));
		case TYPE_NAN:
			throw (not_a_number);
		default:
			throw (impossible);
	}
}

