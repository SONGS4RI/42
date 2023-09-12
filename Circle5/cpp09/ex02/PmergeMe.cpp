/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:25:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/12 13:48:41 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

#define INVALID_INPUT "Error"

PmergeMe* PmergeMe::_ptr;
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char** argv) {
	int idx = 0, num;
	while (argv[++idx]) {
		num = std::atoi(argv[idx]);
		_before.push_back(num);
	}
}

PmergeMe* PmergeMe::getPmergeMe(char** argv) {
	if (!_ptr) {
		_ptr = new PmergeMe(argv);
	}
	return (_ptr);
}

void PmergeMe::isValidElements(void) {
	for (unsigned int i=0; i<_before.size(); i++) {
		if (_before[i] <= 0) throw INVALID_INPUT;
	}
}

void PmergeMe::sortVector() {
	std::vector<std::pair<int, int> > chains;

	for (unsigned int i=0; i<_before.size(); i += 2) {
		std::pair<int, int> chain(-1, -1);
		chain.first = _before[i];
		if (i+1 < _before.size()) chain.second = _before[i+1];
		if (chain.first < chain.second) std::swap(chain.first, chain.second);
		chains.push_back(chain);
	}
	recursiveInsertSortVector(chains, chains.size());
	std::vector<int> main_chain, sub_chain;
	for (unsigned int i=0; i<chains.size(); i++) {
		main_chain.push_back(chains[i].first);
		sub_chain.push_back(chains[i].second);
	}
	fordJohnsonSortVector(main_chain, sub_chain);
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

void PmergeMe::fordJohnsonSortVector(std::vector<int>& mainChain, std::vector<int>&subChain) {
	for (unsigned int i=0; i<_jacobsthal_idx.size(); i++) {
		
	}
}

void PmergeMe::sortList(void) {
	std::list<std::pair<int, int> > chains;

	for (unsigned int i=0; i<_before.size(); i += 2) {
		std::pair<int, int> chain(-1, -1);
		chain.first = _before[i];
		if (i+1 < _before.size()) chain.second = _before[i+1];
		if (chain.first < chain.second) std::swap(chain.first, chain.second);
		chains.push_back(chain);
	}
	recursiveInsertSortList(chains, chains.size());
	std::list<int> main_chain, sub_chain;
	std::list<std::pair<int, int> >::iterator iter = chains.begin();
	for (; iter!= chains.end(); iter++) {
		main_chain.push_back(iter->first);
		sub_chain.push_back(iter->second);
	}
}

void PmergeMe::recursiveInsertSortList(std::list<std::pair<int, int> >& container, int size) {
	if (size == 1) return;
	recursiveInsertSortList(container, size - 1);
	std::list<std::pair<int, int> >::iterator j = container.begin();
	for (int i=0; i<size-1; i++) {
		j++;
	}
	std::pair<int, int> last = *j;
	j--;
	while (std::distance(container.begin(), j) < static_cast<long>(container.size()) &&
		std::distance(container.begin(), j) >= 0 &&
		j->first > last.first) {
		std::list<std::pair<int, int> >::iterator next = j;
		next++;
		next->first = j->first;
		next->second = j->second;
		j--;
	}
	j++;
	j->first = last.first;
	j->second = last.second;
}

const std::vector<int>& PmergeMe::getJacobsthalNumbers() {
	if (_jacobsthal_idx.size() != 0) {
		return (_jacobsthal_idx);
	}
	unsigned int size = _before.size();
	_jacobsthal_idx.push_back(1);

	std::vector<unsigned int> jacob(2, 1);
	int idx = 2;
	while (size > 2 && jacob[idx-1] + 2*jacob[idx-2] < size) {
		jacob.push_back(jacob[idx-1] + 2*jacob[idx-2]);
		idx++;
	}
	for (unsigned int i=2; i<jacob.size(); i++) {
		for (unsigned int j=jacob[i]; j>jacob[i-1]; j--) {
			_jacobsthal_idx.push_back(j);
		}
	}
	for (unsigned int i=_before.size(); i>jacob.back(); i--) {
		_jacobsthal_idx.push_back(i);
	}
	return (_jacobsthal_idx);
}