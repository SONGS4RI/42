/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:13:03 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/24 18:54:23 by jahlee           ###   ########.fr       */
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
	this->_contactInfo[type].resize(10, ' ');
	int idx = 0;
	for (; idx < 10; idx++)
		if (this->_contactInfo[type][idx] != ' ') break ;
	if (idx == 10) return (false);
	return (true);
}