/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/05 17:21:51 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
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
	}

	std::string input;
	int s1_size = s1.size();
	while (std::getline(ifs, input)) {// s1, s2 == ""일때 수정해주자
		int pos = -s1_size;
		while (s1 != "" && (pos = input.find(s1, pos + s1_size)) != -1) {
			input = input.substr(0, pos) + s2 + input.substr(pos + s1_size);
		}
		ofs << input;
		if (!ifs.eof()) ofs << std::endl;
	}
	if (s1 == "") ofs << s2;
	ifs.close();
	ofs.close();
	return (0);
}