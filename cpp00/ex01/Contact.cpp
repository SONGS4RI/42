/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:13:03 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/26 14:31:09 by jahlee           ###   ########.fr       */
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
	int idx = 0;
	int strSize = this->_contactInfo[type].size();
	for (; idx < strSize; idx++)
		if (this->_contactInfo[type][idx] != ' ') break ;
	if (idx == strSize) return (false);
	return (true);
}