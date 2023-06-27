/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:13:03 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/27 16:57:05 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes.hpp"

std::string Contact::getContactInfo(eContact infoType) {
	return (this->_contactInfo[infoType]);
}

void Contact::setContactInfo(std::string str, eContact type) {
	this->_contactInfo[type] = str;
}

bool Contact::isValidContactInput(eContact type) {
	int strSize = this->_contactInfo[type].size();
	if (strSize == 0) return (false);
	return (true);
}

void Contact::printContactNames(void) {
	std::string names[3];
	for(int i = 0; i < 3; i++) {
		eContact infoType = (eContact) i;
		names[i] = this->getContactInfo(infoType);
		if (names[i].size() > 10) {
			names[i].resize(9);
			names[i] += '.';
		}
	}
	std::cout
	// << "|" << std::setw(10) << std::right << contactIdx + 1 << "|"
	<< std::setw(10) << std::right << names[FIRST_NAME] << "|"
	<< std::setw(10) << std::right << names[LAST_NAME] << "|"
	<< std::setw(10) << std::right << names[NICK_NAME] << "|" << std::endl;
	// << "---------------------------------------------" << std::endl;
}

void Contact::printContactInfo(void) {
	std::cout << "First Name     : " << this->_contactInfo[0] << std::endl;
	std::cout << "Last Name      : " << this->_contactInfo[1] << std::endl;
	std::cout << "Nickname       : " << this->_contactInfo[2] << std::endl;
	std::cout << "Phone Number   : " << this->_contactInfo[3] << std::endl;
	std::cout << "Darkest Secret : " << this->_contactInfo[4] << std::endl;
}