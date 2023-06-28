/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:02:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/28 15:36:52 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes.hpp"

// void leaks(void) {
// 	system("leaks ex01");
// }

int main() {
	// atexit(leaks);
	Phonebook newPhonebook = Phonebook();
	std::string input;

	while (42) {
		newPhonebook.printMessage(PROMPT, BLUE);
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cin.clear();
			clearerr(stdin);
			continue ;
		}
		for (int i = 0; i < input.size(); i++)
			if (isupper(input[i])) input[i] = tolower(input[i]);
		if (input == "add") {
			newPhonebook.commandAdd();
		} else if (input == "search") {
			newPhonebook.commandSearch();
		} else if (input == "exit") {
			newPhonebook.commandExit();
		} else {
			newPhonebook.printMessage(WRONG_COMMAND, RED);
		}
	}
	return (0);
}