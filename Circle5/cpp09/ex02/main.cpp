/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:56:33 by jahlee            #+#    #+#             */
/*   Updated: 2023/12/28 16:58:21 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

//   ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Usage ./PmergeMe [num] [...]" << std::endl;
		return (1);
	}
	try {
		PmergeMe* ptr = PmergeMe::getPmergeMe(argv);
		ptr->sortVector();
		ptr->sortList();
	} catch (const char* e) {
		std::cout << e << std::endl;
		delete PmergeMe::getPmergeMe(argv);
		return (1);
	}
	delete PmergeMe::getPmergeMe(argv);
	return (0);
}
