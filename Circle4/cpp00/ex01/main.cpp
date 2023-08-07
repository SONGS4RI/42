/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:02:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/29 17:03:07 by jahlee           ###   ########.fr       */
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
			std::clearerr(stdin);
			continue ;
		}
		for (int i = 0; i < static_cast<int>(input.size()); i++)
			if (std::isupper(input[i])) input[i] = std::tolower(input[i]);
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