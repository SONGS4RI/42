/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:31:12 by jahlee            #+#    #+#             */
/*   Updated: 2024/01/12 18:13:14 by jahlee           ###   ########.fr       */
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
	return ("Date Format Wrong: invalid data format");
}

const char* BitcoinExchange::DuplicatedDateException::what() const throw() {
	return ("Date Format Wrong: duplicated date");
}

const char* BitcoinExchange::InvalidDateException::what() const throw() {
	return ("Date Format Wrong: Year-Month-Day");
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream ifs("data.csv");

	if (ifs.fail()) {
		throw FileOpenException();
	}
	std::string input;
	int year, month, day;
	char delimeters[3];
	double exchange_rate;
	std::getline(ifs, input);
	while (std::getline(ifs, input)) {
		std::istringstream iss(input);
		iss >> year >> delimeters[0] >> month >> delimeters[1]
			>> day >> delimeters[2] >> exchange_rate;
		if (!iss.eof() || iss.fail() || delimeters[0] != '-' ||
			delimeters[1] != '-' || delimeters[2] != ',') throw InvalidFormatException();
		if (!checkVaildDate(year, month, day)) throw InvalidDateException();
		if (_data[year*10000+month*100+day]) throw DuplicatedDateException();
		_data[year*10000+month*100+day] = exchange_rate;
	}
	ifs.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange* BitcoinExchange::getBitcoinExchange(void) {
	if (_btc == NULL) {
		_btc = new BitcoinExchange();
	}
	return (_btc);
}

bool BitcoinExchange::checkVaildDate(const int& year, const int& month, const int& day) const {
	bool leap_year = false;
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) leap_year = true;
	if (month <= 0 || month > 12) return (false);
	if ((day <= 0 || day > days[month]) && !(leap_year && month == 2 && day == 29)) return (false);
	return (true);
}

void BitcoinExchange::calculateInputs(const std::string& filename) {
	std::ifstream ifs(filename.c_str());

	std::string input;
	int year, month, day, date;
	char delimeters[3];
	double value, res;
	std::getline(ifs, input);
	while (std::getline(ifs, input)) {
		std::istringstream iss(input);
		iss >> year >> delimeters[0] >> month >> delimeters[1]
			>> day >> delimeters[2] >> value;
		if (!iss.eof() || iss.fail() || delimeters[0] != '-' ||
			delimeters[1] != '-' || delimeters[2] != '|') {
				std::cout << "Error: bad input => " << input << std::endl;
				continue;
			}
		if (!checkVaildDate(year, month, day)) {
			std::cout << "Error: wrong date => " << input << std::endl;
			continue;
		}
		if (value < 0.0 || value > 1000.0) {
			std::cout << "Error: invalid number" << std::endl;
			continue;
		}
		date = year*10000+month*100+day;
		if (_data.find(date) != _data.end()) {// 데이터를 찾았다면
			res = _data[date] * value;
		} else { // 못찾았다면
			std::map<int,double>::iterator iter = _data.begin();
			for (; iter != _data.end(); iter++) {
				if (iter->first > date) break ;
			}
			if (iter == _data.begin()) {
				std::cout << "Error: data not found" << " => " << input << std::endl;
				continue;
			}
			res = (--iter)->second * value;
		}
		std::cout << input.substr(0, 10) << " => " << value << " = " << res << std::endl;
	}
	ifs.close();
}