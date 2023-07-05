/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:18:07 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/05 16:05:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout
	<< "I love having extra bacon for "
	<< "my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout
	<< "I cannot believe adding extra bacon costs more money."
	<< std::endl
	<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout
	<< "I think I deserve to have some extra bacon for free."
	<< std::endl
	<< "I’ve been coming for years whereas you started working here since last month."
	<< std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout
	<< "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*levels_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int idx = 0;
	for (; idx<4; idx++) {
		if (levels[idx] == level) break ;
	}
	switch (idx)
	{
		case 0:// debug
			(this->*levels_ptr[idx++])();
			std::cout << std::endl;
		case 1:// info
			(this->*levels_ptr[idx++])();
			std::cout << std::endl;
		case 2:// warning
			(this->*levels_ptr[idx++])();
			std::cout << std::endl;
		case 3:// error
			(this->*levels_ptr[idx])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}

Harl::Harl() {
}

Harl::~Harl() {
}