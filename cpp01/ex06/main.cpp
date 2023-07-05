/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:29:51 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/05 17:49:01 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

void leaks(void) {
	std::system("leaks harlFilter");
}

int main(int argc, char **argv) {
	// std::atexit(leaks);
	if (argc != 2) {
		std::cout << "arg error" << std::endl;
		return (1);
	}
	Harl newHarl = Harl();
	newHarl.complain(argv[1]);
	return (0);
}