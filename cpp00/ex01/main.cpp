/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:02:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/21 21:05:05 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Phonebook.hpp"



int main() {
	Phonebook newPhonebook = Phonebook();

	newPhonebook.hi();
	
	std::string input;
	while (std::getline(std::cin, input)) {
		for (int i = 0; i < input.size(); i++)
			if (isupper(input[i])) input[i] = tolower(input[i]);
		if (input == "add") {
			std:: cout << "add" << std::endl;
		} else if (input == "search") {
			std:: cout << "search" << std::endl;
		} else if (input == "exit") {
			std:: cout << "exit" << std::endl;
			break ;
		} else {
			std:: cout << "Wrong Action!!!" << std::endl;
		}
	}
}