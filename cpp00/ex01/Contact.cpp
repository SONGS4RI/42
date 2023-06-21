/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:13:03 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/21 17:51:38 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"

std::string Contact::getFirstName() {
	return (this->_firstName);
}

std::string Contact::getlastName() {
	return (this->_lastName);
}

std::string Contact::getNickName() {
	return (this->_nickName);
}

std::string Contact::getPhoneNumber() {
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret() {
	return (this->_darkestSecret);
}

void Contact::addFirstName(std::string firstname) {
	this->_firstName = firstname;
}

void Contact::addlastName(std::string lastName) {
	this->_lastName = lastName;
}

void Contact::addNickName(std::string nickName) {
	this->_nickName = nickName;
}

void Contact::addPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void Contact::addDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}