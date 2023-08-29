/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:31:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/29 21:05:31 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include "BitcoinExchange.hpp"

const char* BitcoinExchange::FileOpenException::what() const throw() {
	return ("File Open Error");
}

const char* BitcoinExchange::InvalidDateException::what() const throw() {
	return ("Date Format Wrong: Year-Month-Day");
}

const char* BitcoinExchange::InvalidValueException::what() const throw() {
	return ("Value Format Wrong: a float or a positive integer, between 0 and 1000");
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream ifs("data.csv");

	if (ifs.fail()) {
		throw FileOpenException();
	}
	std::string input;
	while (std::getline(ifs, input)) {
		std::istringstream iss(input);
		

	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange* BitcoinExchange::getBitcoinExchange(void) {
	if (_ptr == NULL) {
		_ptr = new BitcoinExchange();
	}
	return (_ptr);
}