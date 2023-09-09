/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:25:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/09 17:29:37 by jahlee           ###   ########.fr       */
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


void PmergeMe::sortVector() {
	std::vector<std::pair<int, int> > v;

	for (unsigned int i=0; i<_before.size(); i += 2) {
		std::pair<int, int> chain(-1, -1);
		chain.first = _before[i];
		if (i+1 < _before.size()) chain.second = _before[i+1];
		if (chain.first < chain.second) std::swap(chain.first, chain.second);
		v.push_back(chain);
	}
	recursiveInsertSortVector(v, v.size());
	std::vector<int> main_chain, sub_chain;
	for (unsigned int i=0; i<v.size(); i++) {
		main_chain.push_back(v[i].first);
		sub_chain.push_back(v[i].second);
	}
	fordJohnsonSortVector(main_chain, sub_chain);
}

void fordJohnsonSortVector(std::vector<int>& mainChain, std::vector<int>&subChain) {
	
}

void PmergeMe::recursiveInsertSortVector(std::vector<std::pair<int, int> >& container, int size) {
	if (size == 1) return;
	recursiveInsertSortVector(container, size - 1);
	std::pair<int, int> last = container[size - 1];
	int j = size - 2;
	while (j >= 0 && container[j].first > last.first) {
		container[j + 1] = container[j];
		j = j - 1;
	}
	container[j+1] = last;
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
	recursiveInsertSortDeque(dq, dq.size());
	std::deque<int> main_chain, sub_chain;
	for (unsigned int i=0; i<dq.size(); i++) {
		main_chain.push_back(dq[i].first);
		sub_chain.push_back(dq[i].second);
	}
	fordJohnsonSortDeque(main_chain, sub_chain);
}

void PmergeMe::recursiveInsertSortDeque(std::deque<std::pair<int, int> >& container, int size) {
	if (size == 1) return;
	recursiveInsertSortDeque(container, size - 1);
	std::pair<int, int> last = container[size - 1];
	int j = size - 2;
	while (j >= 0 && container[j].first > last.first) {
		container[j + 1] = container[j];
		j = j - 1;
	}
	container[j+1] = last;
}

void fordJohnsonSortDeque(std::deque<int>& mainChain, std::deque<int>&subChain) {
	
}

const std::vector<int>& PmergeMe::getJacobsthalNumbers(int size) {
	if (_jacobsthal_numbers.size() != 0) {
		return (_jacobsthal_numbers);
	}
	std::vector<int> jacob(2, 0);
	jacob[1] = 1;
	int idx = 2;
	do {
		jacob.push_back(jacob[idx-1] + 2*jacob[idx-2]);
		idx++;
	} while (jacob[idx-1] + 2*jacob[idx-2] < size);

}