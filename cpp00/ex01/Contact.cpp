/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:13:03 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/26 16:51:13 by jahlee           ###   ########.fr       */
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