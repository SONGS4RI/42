/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:25:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/01 20:03:25 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include "PmergeMe.hpp"

#define INVALID_INPUT "Error"

PmergeMe* PmergeMe::_ptr;
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char** argv) {
	int idx = 0, num;
	while (argv[++idx]) {
		num = std::atoi(argv[idx]);
		if (num <= 0) throw INVALID_INPUT;
		_before.push_back(num);
	}
}

PmergeMe* PmergeMe::getPmergeMe(char** argv) {
	if (!_ptr) {
		_ptr = new PmergeMe(argv);
	}
	return (_ptr);
}

bool PmergeMe::compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return (a.first < b.first);
}

void PmergeMe::sortVector() {
	std::vector<std::pair<int, int> > v;

	for (unsigned int i=0; i<_before.size(); i += 2) {
		std::pair<int, int> chain(-1, -1);
		chain.first = _before[i];
		if (i+1 < _before.size()) chain.second = _before[i+1];
		if (chain.first < chain.second) std::swap(chain.first, chain.second);
		v.push_back(chain);
	}
	std::sort(v.begin(), v.end(), compare);

	// for (unsigned int i=0; i<v.size(); i++) {
	// 	std::cout << v[i].first << " " << v[i].second << " ";
	// }
	// std::cout << "\n";
}

void PmergeMe::sortDeque() {
	std::deque<std::pair<int, int> > dq;

	for (unsigned int i=0; i<_before.size(); i += 2) {
		std::pair<int, int> chain(-1, -1);
		chain.first = _before[i];
		if (i+1 < _before.size()) chain.second = _before[i+1];
		if (chain.first < chain.second) std::swap(chain.first, chain.second);
		dq.push_back(chain);
	}
	std::sort(dq.begin(), dq.end(), compare);
	// for (unsigned int i=0; i<dq.size(); i++) {
	// 	std::cout << dq[i].first << " " << dq[i].second << " ";
	// }
	// std::cout << "\n";

}
