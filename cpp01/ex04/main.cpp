/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/06 20:57:10 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void leaks(void) {
	std::system("leaks ex04");
}

int main(int argc, char **argv) {
	// std::atexit(leaks);
	if (argc != 4) {
		std::cerr << "argv error" << std::endl;
		return (1);
	}
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::ifstream ifs(filename, std::ios::in);

	if (ifs.fail()) {
		std::cerr << "open error" << std::endl;
		return (1);
	}
	std::ofstream ofs(filename + ".replace", std::ios::out | std::ios::trunc);
	if (ofs.fail()) {
		std::cerr << "file make error" << std::endl;
		return (1);
	}

	std::string input;
	int s1_size = s1.size();
	int s2_size = s2.size();
	int diff = s2_size - s1_size;

	std::getline(ifs, input, '\000');
	int pos = 0;
	while (s1 != "" && (pos = input.find(s1, pos)) != -1) {
		input.erase(input.begin() + pos, input.begin() + pos + s1_size);
		for (int i=0; i<s2_size; i++)
			input.insert(input.begin() + pos + i, s2[i]);
		pos += diff;
		if (pos < 0) pos = 0;
	}
	ofs << input;
	if (s1 == "") ofs << s2;
	ifs.close();
	ofs.close();
	return (0);
}