/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:43:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/21 20:32:20 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Phonebook.hpp"

Phonebook::Phonebook() {
	this->_cnt = 0;
	this->_oldestIdx = 0;
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

void Phonebook::hi() {
	std::cout << "hi" << std::endl;
}