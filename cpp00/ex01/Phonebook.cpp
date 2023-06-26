/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:43:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/26 16:46:26 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes.hpp"

Phonebook::Phonebook() {
	this->_message[PROMPT] = "Type Command [ ADD or SEARCH or EXIT ]";
	this->_message[ADD] = "Type Contact Information One Field At A Time\n"
	"[ First Name, Last Name, Nickname, Phone Number, And Darkest Secret ]";
	this->_message[SEARCH] = "search";
	this->_message[EXIT] = "Exit";
	this->_message[WRONG_COMMAND] = "Wrong Command!!!";
	this->_message[WRONG_CONTACT_INFO] = "Wrong Contact Info!!!";
	this->_message[EMPTY] = "Phonebook Empty";
	this->_message[WRONG_IDX] = "Wrong Index";
	this->_message[WRONG_IDX_RANGE] = "Wrong Index Range";
	this->_cnt = 0;
	this->_oldestIdx = 0;
}

void Phonebook::printMessage(eMessage type, std::string color) {
	std::cout << color << this->_message[type] << RESET << std::endl;
}

void Phonebook::addContact(Contact newContact) {
	if (this->_cnt == 8) {
		_contacts[this->_oldestIdx] = newContact;
		this->_oldestIdx = (this->_oldestIdx + 1) % 8;
	} else {
		_contacts[this->_cnt] = newContact;
		this->_cnt++;
	}
}

void Phonebook::commandAdd() {
	this->printMessage(ADD, BLUE);
	Contact newContact = Contact();
	std::string contactInput;
	for (int i = 0; i < 5; i++) {
		std::getline(std::cin, contactInput);
		int idx = 0;
		for (;idx < contactInput.size(); idx++) {
			if (contactInput[idx] != ' ') break ;
		}
		contactInput = contactInput.substr(idx);
		newContact.setContactInfo(contactInput, (eContact) i);
		if (!newContact.isValidContactInput((eContact) i)) {
			this->printMessage(WRONG_CONTACT_INFO, RED);
			return ;
		}
	}
	this->addContact(newContact);
}

void Phonebook::printContactNames(unsigned int contactIdx) {
	Contact targetContact = this->_contacts[contactIdx];
	std::string names[3];
	for(int i = 0; i < 3; i++) {
		eContact infoType = (eContact) i;
		names[i] = targetContact.getContactInfo(infoType);
		if (names[i].size() > 10) {
			names[i].resize(9);
			names[i] += '.';
		}
	}
	std::cout
	<< "---------------------------------------------" << std::endl
	<< "|     index|first name| last name|  nickname|" << std::endl
	<< "---------------------------------------------" << std::endl
	<< "|" << std::setw(10) << std::right << contactIdx + 1 << "|"
	<< std::setw(10) << std::right << names[FIRST_NAME] << "|"
	<< std::setw(10) << std::right << names[LAST_NAME] << "|"
	<< std::setw(10) << std::right << names[NICK_NAME] << "|" << std::endl
	<< "---------------------------------------------" << std::endl;
}

void Phonebook::commandSearch() {
	if (this->_cnt == 0) {
		this->printMessage(EMPTY, YELLOW);
		return ;
	}
	std::string inputIdx;
	while (42) {
		std::cout << BLUE "type in index 1 ~ " << this->_cnt << " want to see" RESET << std::endl;
		std::getline(std::cin, inputIdx);
		if (inputIdx.size() != 1) {
			this->printMessage(WRONG_IDX, YELLOW);
		} else if (inputIdx[0] < '1' || inputIdx[0] > this->_cnt + '0') {
			this->printMessage(WRONG_IDX_RANGE, YELLOW);
		} else {
			break ;
		}
	}
	this->printContactNames(inputIdx[0] - '1');
}

void Phonebook::commandExit() {
	this->printMessage(EXIT, YELLOW);
	exit(0);
}