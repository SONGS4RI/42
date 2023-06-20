/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:31:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/20 20:23:08 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string name;
		std::string phoneNumber;
	public:
		Contact(std::string name, std::string phoneNumber) {
			this->name = name;
			this->phoneNumber = phoneNumber;
			std:: cout << "Contact가 생성되었습니다." << std::endl;
		}
		std::string getName() {
			return (name);
		}
		std::string getPhoneNumber() {
			return (phoneNumber);
		}
};
#endif