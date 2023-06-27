/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:31:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/27 16:55:00 by jahlee           ###   ########.fr       */
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
		Phonebook(void);
		void addContact(Contact contact);
		void printMessage(eMessage type, std::string color);
		void commandAdd(void);
		void commandSearch(void);
		void commandExit(void);
};
#endif