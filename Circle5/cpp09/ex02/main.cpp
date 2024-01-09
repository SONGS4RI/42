/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:56:33 by jahlee            #+#    #+#             */
/*   Updated: 2024/01/09 20:38:52 by jahlee           ###   ########.fr       */
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
		ptr->checkResult();
		std::cout << "Before:";
		std::vector<int>::iterator iter = ptr->_before.begin();
		for (; iter != ptr->_before.end(); iter++) {
			std::cout << " " << *iter;
		}
		std::cout << "\n";
		std::cout << "After:";
		iter = ptr->_after_vector.begin();
		for (; iter != ptr->_after_vector.end(); iter++) {
			std::cout << " " << *iter;
		}
		std::cout << "\n";
		std::cout << "After:";
		std::list<int>::iterator l = ptr->_after_list.begin();
		for (; l != ptr->_after_list.end(); l++) {
			std::cout << " " << *l;
		}
		std::cout << "\n";
		std::cout << std::fixed << "Time to process a range of " << ptr->_after_vector.size()
		<< " elements with std::vector : " << ptr->_v_time << " us\n";
		std::cout << std::fixed << "Time to process a range of " << ptr->_after_list.size()
		<< " elements with std::list : " << ptr->_l_time << " us\n";
	} catch (const char* e) {
		std::cout << e << std::endl;
		delete PmergeMe::getPmergeMe(argv);
		return (1);
	}
	delete PmergeMe::getPmergeMe(argv);
	return (0);
}
