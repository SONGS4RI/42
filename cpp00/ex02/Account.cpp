/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:35:13 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/26 19:42:07 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <ctime>
#include <iostream>

Account::Account(int initial_deposit) {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void Account::_displayTimestamp( void ) {
	time_t timer = time(NULL);
 	struct tm *local = localtime(&timer);
	std::string year = std::to_string(local->tm_year + 1900);
	std::string mon = std::to_string(local->tm_mon + 1);
	if (mon.size() == 1) mon = "0" + mon;
	std::string mday = std::to_string(local->tm_mday);
	if (mday.size() == 1) mday = "0" + mday;
	std::string hour = std::to_string(local->tm_hour);
	if (hour.size() == 1) hour = "0" + hour;
	std::string min = std::to_string(local->tm_min);
	if (min.size() == 1) min = "0" + min;
	std::string sec = std::to_string(local->tm_sec);
	if (sec.size() == 1) sec = "0" + sec;
	std::cout << "[" << year + mon + mday << "_" << hour + min + sec << "]";
}