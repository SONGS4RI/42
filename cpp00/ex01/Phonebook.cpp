/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:43:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/24 18:56:28 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes.hpp"

Phonebook::Phonebook() {
	this->_message[PROMPT] = "type command [ ADD or SEARCH or EXIT ]";
	this->_message[ADD] = "type contact information one field at a time\n"
	"[ first name, last name, nickname, phone number, and darkest secret ]";
	this->_message[SEARCH] = "search";
	this->_message[EXIT] = "exit";
	this->_message[WRONG] = "Wrong Action!!!";
	this->_message[ERROR] = "ERROR OCCURED!!!";
	this->_cnt = 0;
	this->_oldestIdx = 0;
}

void Phonebook::printMessage(eMessage type, std::string color) {
	std::cout << color << this->_message[type] << RESET << std::endl;
}

void Phonebook::addContact(Contact contact) {
	if (this->_cnt == 8) {
		_contacts[this->_oldestIdx] = contact;
		this->_oldestIdx = (this->_oldestIdx + 1) % 8;
	} else {
		_contacts[this->_cnt] = contact;
		this->_cnt++;
	}
}

void Phonebook::commandAdd() {
	this->printMessage(ADD, BLUE);
	Contact newContact = Contact();
	std::string contactInput;
	for (int i = 0; i < 5; i++) {
		std::getline(std::cin, contactInput);
		newContact.setContactInfo(contactInput, (eContact) i);
		if (!newContact.isValidContactInput((eContact) i)) {
			this->printMessage(ERROR, RED);
			this->printMessage(EXIT, RED);
			return ;
		}
	}
	this->addContact(newContact);
	for (int i = 0; i < 5; i++) {///////////////////////
	std::cout << "Info[" << i << "] : " << this->_contacts[0].getContactInfo((eContact) i) << "\n";
	}
}

void Phonebook::commandSearch() {

}

void Phonebook::commandExit() {
	this->printMessage(EXIT, YELLOW);
}