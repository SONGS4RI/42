/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:31:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/20 20:46:57 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "./Contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		unsigned int cnt;
		unsigned int oldestIdx;

	public:
		Phonebook() {
				this->cnt = 0;
				this->oldestIdx = 0;
				std:: cout << "Phonebook이 생성되었습니다." << std::endl;
			}

		void addContact(Contact contact) {
			if (this->cnt == 8) {
				contacts[this->oldestIdx] = contact;
				this->oldestIdx = (this->oldestIdx + 1) % 8;
			} else {
				contacts[this->cnt] = contact;
				this->cnt++;
			}
		}

		~Phonebook() {
			std:: cout << "Phonebook이 소멸되었습니다." << std::endl;
		}
};

#endif