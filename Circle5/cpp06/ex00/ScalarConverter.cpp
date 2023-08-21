/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:24:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/21 16:41:38 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"


const char* ScalarConverter::CanNotConvertException::what() const throw() {
	return ("Can Not Convert Input Exception");
}

void ScalarConverter::convert(const std::string& input) {
	EType type = detectType(input);
	switch (type) {
		case TYPE_CHAR:
			std::cout << "TYPE_CHAR" << std::endl;
			break;
		case TYPE_INT:
			std::cout << "TYPE_INT" << std::endl;
			break;
		case TYPE_FLOAT:
			std::cout << "TYPE_FLOAT" << std::endl;
			break;
		case TYPE_DOUBLE:
			std::cout << "TYPE_DOUBLE" << std::endl;
			break;
		default:
			throw (CanNotConvertException());
			break;
	}
}

EType ScalarConverter::detectType(const std::string& input) {
	int input_size = input.size();
	if (input_size == 1 && !std::isdigit(input[0])) return (TYPE_CHAR);
	int dot_idx = -1, f_idx = -1;
	for (int i=0; i<input_size; i++) {
		if (input[i] == '.' && dot_idx == -1) {
			dot_idx = i;
		} else if (input[i] == 'f' && i == input_size - 1) {
			f_idx = i;
		} else if (!std::isdigit(input[i])) {
			throw (CanNotConvertException());
		}
	}
	if (dot_idx == -1) {
		return (TYPE_INT);
	} else if (f_idx != -1) {
		return (TYPE_FLOAT);
	}
	return (TYPE_DOUBLE);
}