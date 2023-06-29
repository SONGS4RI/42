/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:55:25 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/29 17:02:19 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void makeDefaultMegapehonSound() {
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void argvToUpper(int argc, char ***argv){
	for (int i = 1; i < argc; i++)
		for (int j = 0; (*argv)[i][j] != '\0'; j++)
			if (std::islower((*argv)[i][j])) (*argv)[i][j] = std::toupper((*argv)[i][j]);
}

void makeMegaphoneSound(int argc, char **argv) {
	argvToUpper(argc, &argv);
	for (int i = 1; i < argc; i++) std::cout << argv[i];
	std::cout << std::endl;
	return ;
}

int main(int argc, char **argv) {
	if (argc == 1) makeDefaultMegapehonSound();
	else makeMegaphoneSound(argc, argv);
	return (0);
}