/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:43:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/28 18:33:31 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes.hpp"

void Phonebook::setMessages(void) {
	this->_messages[PROMPT] = "Type Command [ ADD or SEARCH or EXIT ]";
	this->_messages[ADD] = "Type Contact Information One Field At A Time\n"
	"[ First Name, Last Name, Nickname, Phone Number, And Darkest Secret ]";
	this->_messages[SEARCH] = "search";
	this->_messages[EXIT] = "Exit";
	this->_messages[WRONG_COMMAND] = "Wrong Command!!!";
	this->_messages[WRONG_CONTACT_INFO] = "Wrong Contact Info!!!";
	this->_messages[EMPTY] = "Phonebook Empty";
	this->_messages[WRONG_IDX] = "Wrong Index";
}

Phonebook::Phonebook(void) {
	this->setMessages();
	this->_cnt = 0;
	this->_oldestIdx = 0;
}

void Phonebook::printMessage(eMessage type, std::string color) {
	std::cout << color << this->_messages[type] << RESET << std::endl;
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

void Phonebook::commandAdd(void) {
	this->printMessage(ADD, BLUE);
	Contact newContact = Contact();
	std::string contactInput;
	for (int i = 0; i < 5; i++) {
		std::getline(std::cin, contactInput);
		if (std::cin.eof()) {
			std::cin.clear();
			clearerr(stdin);
			return ;
		}
		int idx = 0;
		for (;idx < contactInput.size(); idx++) {
			if (contactInput[idx] != ' ') break ;
		}
		if (!newContact.setContactInfo(contactInput.substr(idx), (eContact) i)) {
			this->printMessage(WRONG_CONTACT_INFO, RED);
			this->commandAdd();
			return ;
		}
	}
	this->addContact(newContact);
}

void Phonebook::commandSearch(void) {
	if (this->_cnt == 0) {
		this->printMessage(EMPTY, YELLOW);
		return ;
	}
	std::cout
	<< "==============================================" << std::endl
	<< "|     index|first name| last name|  nickname|" << std::endl
	<< "==============================================" << std::endl;
	for (int idx = 1; idx <= this->_cnt; idx++) {
		std::cout << "|" << std::setw(10) << std::right << idx << "|";
		this->_contacts[idx - 1].printContactNames();
		std::cout << "==============================================" << std::endl;
	}
	std::string inputIdx;
	while (42) {
		std::cout << BLUE "type in index < 1 ~ " << this->_cnt << " >" RESET << std::endl;
		std::getline(std::cin, inputIdx);
		if (std::cin.eof()) {
			std::cin.clear();
			clearerr(stdin);
			return ;
		} else if (inputIdx.size() != 1 || inputIdx[0] < '1' || inputIdx[0] > this->_cnt + '0') {
			this->printMessage(WRONG_IDX, YELLOW);
		} else {
			break ;
		}
	}
	this->_contacts[inputIdx[0] - '1'].printContactInfo();
}

void Phonebook::commandExit(void) {
	this->printMessage(EXIT, YELLOW);
	exit(0);
}