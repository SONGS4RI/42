/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:31:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/21 20:25:49 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "./Contact.hpp"

class Phonebook {
	private:
		Contact _contacts[8];
		unsigned int _cnt;
		unsigned int _oldestIdx;

	public:
		Phonebook();
		void addContact(Contact contact);
		void getContacts();
		void hi();
};
#endif