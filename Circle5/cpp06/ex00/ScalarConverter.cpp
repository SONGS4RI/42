/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:24:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/22 20:47:08 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <cctype>
#include "ScalarConverter.hpp"

#define _IMPOSSIBLE "impossible"
#define _NOT_DISPLAYABLE "Non displayable"
#define _NOT_A_NUMBER_F "nanf"
#define _NOT_A_NUMBER_D "nan"

std::string ScalarConverter::_input = "";

void ScalarConverter::convert(const std::string& input) {
	std::cout.precision(30);
	_input = input;
	EType type = detectType();
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
			std::cout << "Type: NaN" << std::endl;
			break;
		default:
			break;
	}

	std::cout << "char: ";
	try {
		std::cout << convertToChar(type);
	} catch (const char* e) {
		std::cout << e;
	}
	std::cout<< std::endl;

	std::cout << "int: ";
	try {
		std::cout << convertToInt(type);
	} catch (const char* e) {
		std::cout << e;
	}
	std::cout<< std::endl;

	std::cout << "float: ";
	try {
		std::cout << convertToFloat(type);
		if (convertToFloat(type) == static_cast<float>(stoi(_input))) std::cout << ".0";/////고쳐야함
		std::cout << "f";
	} catch (const char* e) {
		std::cout << e;
	} catch (std::out_of_range& o) {
	}
	std::cout<< std::endl;

	std::cout << "double: ";
	try {
		std::cout << convertToDouble(type);
		if (convertToDouble(type) == static_cast<double>(stoi(_input))) std::cout << ".0";
	} catch (const char* e) {
		std::cout << e;
	} catch (std::out_of_range& o) {
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
		} else if (_input[i] == 'f' && i == input_size - 1 && dot_idx != -1) {
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

char ScalarConverter::convertToChar(const EType& type) {
	int res_i; float res_f; double res_d;
	switch (type) {
		case TYPE_CHAR:
			if (!std::isprint(_input[0])) throw (_NOT_DISPLAYABLE);
			return (_input[0]);
		case TYPE_INT:
			try {
				res_i = std::stoi(_input);
			} catch (std::out_of_range& o) {
				throw (_IMPOSSIBLE);
			}
			if (res_i < 0 || 256 <= res_i) throw (_IMPOSSIBLE);
			if (!std::isprint(res_i)) throw (_NOT_DISPLAYABLE);
			return (static_cast<char>(res_i));
		case TYPE_FLOAT:
			try {
				res_f = std::stof(_input);
			} catch (std::out_of_range& o) {
				throw (_IMPOSSIBLE);
			}
			if (res_f < 0 || 256 <= res_f) throw (_IMPOSSIBLE);
			if (!std::isprint(res_f)) throw (_NOT_DISPLAYABLE);
			return (static_cast<char>(res_f));
		case TYPE_DOUBLE:
			try {
				res_d = std::stod(_input);
			} catch (std::out_of_range& o) {
				throw (_IMPOSSIBLE);
			}
			if (res_d < 0 || 256 <= res_d) throw (_IMPOSSIBLE);
			if (!std::isprint(res_d)) throw (_NOT_DISPLAYABLE);
			return (static_cast<char>(res_d));
		default:
			throw (_IMPOSSIBLE);
	}
}

int ScalarConverter::convertToInt(const EType& type) {
	int res_i; float res_f; double res_d;
	switch (type) {
		case TYPE_CHAR:
			return (static_cast<int>(_input[0]));
		case TYPE_INT:
			try {
				res_i = std::stoi(_input);
			} catch (std::out_of_range& e) {
				throw (_IMPOSSIBLE);
			}
			return (res_i);
		case TYPE_FLOAT:
			try {
				res_i = std::stoi(_input);
				res_f = std::stof(_input);
			} catch (std::out_of_range& e) {
				throw (_IMPOSSIBLE);
			}
			return (static_cast<int>(res_f));
		case TYPE_DOUBLE:
			try {
				res_i = std::stoi(_input);
				res_d = std::stod(_input);
			} catch (std::out_of_range& e) {
				throw (_IMPOSSIBLE);
			}
			return (static_cast<int>(res_d));
		default:
			throw (_IMPOSSIBLE);
	}
}

float ScalarConverter::convertToFloat(const EType& type) {
	float res_f; double res_d;
	switch (type) {
		case TYPE_CHAR:
			return (static_cast<float>(_input[0]));
		case TYPE_INT:
			return (static_cast<float>(std::stoi(_input)));
		case TYPE_FLOAT:
			try {
				res_f = std::stof(_input);
			} catch (std::out_of_range& e) {
				throw (_IMPOSSIBLE);
			}
			return (res_f);
		case TYPE_DOUBLE:
			try {
				res_f = std::stof(_input);
				res_d = std::stod(_input);
			} catch (std::out_of_range& e) {
				throw (_IMPOSSIBLE);
			}
			return (static_cast<float>(res_d));
		case TYPE_NAN:
			throw (_NOT_A_NUMBER_F);
		default:
			throw (_IMPOSSIBLE);
	}
}

double ScalarConverter::convertToDouble(const EType& type) {
	double res_d;
	switch (type) {
		case TYPE_CHAR:
			return (static_cast<double>(_input[0]));
		case TYPE_INT:
			return (static_cast<double>(std::stoi(_input)));
		case TYPE_FLOAT:
			return (static_cast<double>(std::stof(_input)));
		case TYPE_DOUBLE:
			try {
				res_d = std::stod(_input);
			} catch (std::out_of_range& e) {
				throw (_IMPOSSIBLE);
			}
			return (res_d);
		case TYPE_NAN:
			throw (_NOT_A_NUMBER_D);
		default:
			throw (_IMPOSSIBLE);
	}
}

