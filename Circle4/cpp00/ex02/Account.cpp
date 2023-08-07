/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:35:13 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/29 17:20:59 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout
	<< "accounts:" << Account::_nbAccounts << ";"
	<< "total:" << Account::_totalAmount << ";"
	<< "deposits:" << Account::_totalNbDeposits << ";"
	<< "withdrawals:" << Account::_totalNbWithdrawals
	<< std::endl;
}

Account::Account(int initial_deposit) {
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "created"
	<< std::endl;
}

Account::~Account() {
	this->_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "closed"
	<< std::endl;
}

void	Account::makeDeposit(int deposit) {
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	this->_amount += deposit;
	this->_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount - deposit << ";"
	<< "deposit:" << deposit << ";"
	<< "amount:" << this->_amount << ";"
	<< "nb_deposits:" << ++this->_nbDeposits
	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	this->_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount) {
		std::cout
		<< "withdrawal:refused"
		<< std::endl;
		return (false);
	}
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	std::cout
	<< "withdrawal:" << withdrawal << ";"
	<< "amount:" << this->_amount << ";"
	<< "nb_withdrawals:" << ++this->_nbWithdrawals
	<< std::endl;
	return (true) ;
}

int		Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->checkAmount() << ";"
	<< "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}

void Account::_displayTimestamp(void) {
	time_t timer = std::time(NULL);
 	struct tm *local = std::localtime(&timer);
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
	std::cout << "[" << year + mon + mday << "_" << hour + min + sec << "] ";
}

Account::Account(void) {
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = 0;
	this->_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "created"
	<< std::endl;
}