/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:29:51 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/05 17:50:59 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

void leaks(void) {
	std::system("leaks ex05");
}

int main(void) {
	// std::atexit(leaks);
	Harl newHarl = Harl();

	newHarl.complain("debug");
	newHarl.complain("info");
	newHarl.complain("warning");
	newHarl.complain("error");

	return (0);
}