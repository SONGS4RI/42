/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:31:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/21 17:50:14 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		std::string getFirstName();
		std::string getlastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		void addFirstName(std::string firstname);
		void addlastName(std::string lastName);
		void addNickName(std::string nickName);
		void addPhoneNumber(std::string phoneNumber);
		void addDarkestSecret(std::string darkestSecret);
};
#endif