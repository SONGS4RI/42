/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:31:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/26 16:43:31 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "./includes.hpp"

class Phonebook {
	private:
		Contact			_contacts[8];
		std::string		_message[9];
		unsigned int	_cnt;
		unsigned int	_oldestIdx;

	public:
		Phonebook();
		void addContact(Contact contact);
		void getContacts();
		void printMessage(eMessage type, std::string color);
		void printContactNames(unsigned int contactIdx);
		void commandAdd();
		void commandSearch();
		void commandExit();
};
#endif