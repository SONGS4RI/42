/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:24:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/23 17:30:06 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <cctype>
#include "ScalarConverter.hpp"

#define _IMPOSSIBLE "impossible"
#define _NOT_DISPLAYABLE "Non displayable"
#define _NOT_A_NUMBER "nan"

std::string ScalarConverter::_input;

void ScalarConverter::convert(const std::string& input) {
	_input = input;
	EType type = detectType();

	std::cout << "char: ";
	try {
		std::cout << convertToChar(type);
	} catch (const char* e) {
		std::cout << e;
	} catch (std::out_of_range& o) {
		std::cout << _IMPOSSIBLE;
	}
	std::cout << std::endl;

	std::cout << "int: ";
	try {
		std::cout << convertToInt(type);
	} catch (const char* e) {
		std::cout << e;
	} catch (std::out_of_range& o) {
		std::cout << _IMPOSSIBLE;
	}
	std::cout << std::endl;

	std::cout << "float: ";
	try {
		float res_f = convertToFloat(type);
		std::cout << res_f;
		if (std::abs(res_f) < std::powf(10,6) &&
			convertToFloat(type) == std::floor(stof(_input)) &&
			std::abs(res_f) != 1.0f/0.0f) std::cout << ".0";
		std::cout << "f";
	} catch (const char* e) {
		std::cout << e << "f";
	} catch (std::out_of_range& o) {
		std::cout << _IMPOSSIBLE;
	}
	std::cout << std::endl;

	std::cout << "double: ";
	try {
		double res_d = convertToDouble(type);
		std::cout << res_d;
		if (std::abs(res_d) < std::powf(10,6) &&
			convertToDouble(type) == std::floor(stod(_input)) &&
			std::abs(res_d) != 1.0/0.0) std::cout << ".0";
	} catch (const char* e) {
		std::cout << e;
	} catch (std::out_of_range& o) {
		std::cout << _IMPOSSIBLE;
	}
	std::cout << std::endl;
}

EType ScalarConverter::detectType() {
	int input_size = _input.size();
	double converted = std::strtod(_input.c_str(), NULL);
	if (std::abs(converted) == 1.0 / 0.0) {
		if (_input[input_size-2] == 'f') {
			std::cout << "Type: Float" << std::endl;
			return (TYPE_FLOAT);
		}
		std::cout << "Type: Double" << std::endl;
		return (TYPE_DOUBLE);
	}
	if (input_size == 1 && !std::isdigit(_input[0])) {
		std::cout << "Type: Char" << std::endl;
		return (TYPE_CHAR);
	}
	int dot_idx = -1, f_idx = -1, sign = 0;
	if (_input[0] == '+' || _input[0] == '-') sign++;
	for (int i=sign; i<input_size; i++) {
		if (_input[i] == '.' && dot_idx == -1 && i != 0) {
			dot_idx = i;
		} else if (_input[i] == 'f' && i == input_size - 1 && dot_idx != -1) {
			f_idx = i;
		} else if (!std::isdigit(_input[i])) {
			std::cout << "Type: NaN" << std::endl;
			return (TYPE_NAN);
		}
	}
	if (dot_idx == -1) {
		std::cout << "Type: Int" << std::endl;
		return (TYPE_INT);
	}
	if (f_idx != -1) {
		std::cout << "Type: Float" << std::endl;
		return (TYPE_FLOAT);
	}
	std::cout << "Type: Double" << std::endl;
	return (TYPE_DOUBLE);
}

char ScalarConverter::convertToChar(const EType& type) {
	int res_i; float res_f; double res_d;
	switch (type) {
		case TYPE_CHAR:
			if (!std::isprint(_input[0])) throw (_NOT_DISPLAYABLE);
			return (_input[0]);
		case TYPE_INT:
			res_i = std::stoi(_input);
			if (res_i < 0 || 256 <= res_i) throw (_IMPOSSIBLE);
			if (!std::isprint(res_i)) throw (_NOT_DISPLAYABLE);
			return (static_cast<char>(res_i));
		case TYPE_FLOAT:
			res_f = std::stof(_input);
			if (res_f < 0 || 256 <= res_f) throw (_IMPOSSIBLE);
			if (!std::isprint(res_f)) throw (_NOT_DISPLAYABLE);
			return (static_cast<char>(res_f));
		case TYPE_DOUBLE:
			res_d = std::stod(_input);
			if (res_d < 0 || 256 <= res_d) throw (_IMPOSSIBLE);
			if (!std::isprint(res_d)) throw (_NOT_DISPLAYABLE);
			return (static_cast<char>(res_d));
		default:
			throw (_IMPOSSIBLE);
	}
}

int ScalarConverter::convertToInt(const EType& type) {
	float res_f; double res_d;
	switch (type) {
		case TYPE_CHAR:
			return (static_cast<int>(_input[0]));
		case TYPE_INT:
			return (std::stoi(_input));
		case TYPE_FLOAT:
			res_f = std::stof(_input);
			if (std::abs(res_f) == 1.0f / 0.0) throw (_IMPOSSIBLE);
			std::stoi(_input);
			return (static_cast<int>(res_f));
		case TYPE_DOUBLE:
			res_d = std::stod(_input);
			if (std::abs(res_d) == 1.0f / 0.0) throw (_IMPOSSIBLE);
			std::stoi(_input);
			return (static_cast<int>(res_d));
		default:
			throw (_IMPOSSIBLE);
	}
}

float ScalarConverter::convertToFloat(const EType& type) {
	double res_d;
	switch (type) {
		case TYPE_CHAR:
			return (static_cast<float>(_input[0]));
		case TYPE_INT:
			return (static_cast<float>(std::stoi(_input)));
		case TYPE_FLOAT:
			return (std::stof(_input));
		case TYPE_DOUBLE:
			std::stof(_input);
			res_d = std::stod(_input);
			return (static_cast<float>(res_d));
		case TYPE_NAN:
			throw (_NOT_A_NUMBER);
		default:
			throw (_IMPOSSIBLE);
	}
}

double ScalarConverter::convertToDouble(const EType& type) {
	switch (type) {
		case TYPE_CHAR:
			return (static_cast<double>(_input[0]));
		case TYPE_INT:
			return (static_cast<double>(std::stoi(_input)));
		case TYPE_FLOAT:
			return (static_cast<double>(std::stof(_input)));
		case TYPE_DOUBLE:
			return (std::stod(_input));
		case TYPE_NAN:
			throw (_NOT_A_NUMBER);
		default:
			throw (_IMPOSSIBLE);
	}
}

