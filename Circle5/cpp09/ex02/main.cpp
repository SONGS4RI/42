/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:56:33 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/01 18:00:37 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

//  ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Usage ./PmergeMe [num] [...]" << std::endl;
		return (1);
	}
	try {
		PmergeMe* ptr = PmergeMe::getPmergeMe(argv);
		ptr->sortVector();
		ptr->sortDeque();
	} catch (const char* e) {
		std::cout << e << std::endl;
		delete PmergeMe::getPmergeMe(argv);
		return (1);
	}
	delete PmergeMe::getPmergeMe(argv);
	return (0);
}

/*

int n;

vector<int> v(2, 0); v[1] = 1;

int idx = 2;
while (1) {
	int next_num = v[idx-1] + 2*v[idx-2];
	if (next_num > n) break;
	v.push_back(next_num);
}

*/
