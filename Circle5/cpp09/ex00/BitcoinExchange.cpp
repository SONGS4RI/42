/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:31:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/30 17:09:05 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange* BitcoinExchange::_btc;

const char* BitcoinExchange::FileOpenException::what() const throw() {
	return ("File Open Error");
}

const char* BitcoinExchange::InvalidFormatException::what() const throw() {
	return ("Date Format Wrong: duplicated date");
}

const char* BitcoinExchange::DuplicatedDateException::what() const throw() {
	return ("Date Format Wrong: duplicated date");
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
	std::string input, date;
	int year, month, day;
	char delimeters[3];
	double exchange_rate;
	while (std::getline(ifs, input)) {
		std::istringstream iss(input);
		iss >> year >> delimeters[0] >> month >> delimeters[1] >> day >> exchange_rate;
		if (delimeters[0] != '-' || delimeters[1] != '-' ||
			delimeters[2] != ',') throw InvalidFormatException();
		checkVaildDate(year, month, day);
		if (_data[year*1000+month*10+day]) {
			throw DuplicatedDateException();
		}
		_data[year*1000+month*10+day] = exchange_rate;
	}
}

BitcoinExchange::~BitcoinExchange() {
	for (std::map<int, double>::iterator iter = _data.begin(); iter != _data.end(); iter++) {
		std::cout << iter->first << " | " << iter->second << std::endl;
	}
}

BitcoinExchange* BitcoinExchange::getBitcoinExchange(void) {
	if (_btc == NULL) {
		_btc = new BitcoinExchange();
	}
	return (_btc);
}

void BitcoinExchange::checkVaildDate(const int& year, const int& month, const int& day) const {
	bool leap_year = false;
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0 && (year % 100 == 0 | year % 400 == 0)) leap_year = true;
	if (month <= 0 || month > 12) throw InvalidDateException();
	if ((day <= 0 || day > days[month]) &&
		!(leap_year && month == 2 && day == 29)) throw InvalidDateException();
}
