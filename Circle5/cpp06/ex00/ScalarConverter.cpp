/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:24:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/19 21:04:00 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"


const char* ScalarConverter::CanNotConvertException::what() const throw() {
	return ("Can Not Convert input exception");
}

void ScalarConverter::convert(const std::string& input) {
	EType type = detectType(input);
	switch (type) {
		case TYPE_CHAR:
			break;
		case TYPE_INT:
			break;
		case TYPE_FLOAT:
			break;
		case TYPE_DOUBLE:
			break;
		default:
			throw(CanNotConvertException());
			break;
	}
}

EType ScalarConverter::detectType(const std::string& input) {
	
	return (TYPE_INT);
}