/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:29:51 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/05 15:10:43 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

void leaks(void) {
	system("leaks ex05");
}

int main(void) {
	atexit(leaks);
	Harl newHarl = Harl();

	std::cout << "[ Level: debug ]" << std::endl;
	newHarl.complain("debug");
	std::cout << "[ Level: info ]" << std::endl;
	newHarl.complain("info");
	std::cout << "[ Level: warning ]" << std::endl;
	newHarl.complain("warning");
	std::cout << "[ Level: error ]" << std::endl;
	newHarl.complain("error");

	return (0);
}