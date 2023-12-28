/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:25:08 by jahlee            #+#    #+#             */
/*   Updated: 2023/12/28 18:44:05 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

#define INVALID_INPUT "invalid input error"

PmergeMe* PmergeMe::_ptr;
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char** argv) {
	int idx = 0, num;
	while (argv[++idx]) {
		num = std::atoi(argv[idx]);
		_before.push_back(num);
	}
	isValidElements();
	getJacobsthalNumbers();
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

void PmergeMe::getJacobsthalNumbers() {
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
	mergeSortVector(chains, 0, chains.size() - 1, 0);
	std::vector<int> main_chain, sub_chain;
	for (unsigned int i=0; i<chains.size(); i++) {
		main_chain.push_back(chains[i].first);
		sub_chain.push_back(chains[i].second);
	}
	// fordJohnsonSortVector(main_chain, sub_chain);
}

void PmergeMe::mergeSortVector(std::vector<std::pair<int, int> >& container, int low, int high, int depth) {
	
}

void PmergeMe::mergeVector(std::vector<std::pair<int, int> >& container, int low, int high) {
	int mid = (low + high) / 2;
    int leftSize = mid - low + 1, rightSize = high - mid;
	std::vector<std::pair<int, int> >::iterator iterLow = container.begin() + low;

    std::vector<std::pair<int, int>> leftArr(iterLow, container.begin() + mid);
	std::vector<std::pair<int, int>> rightArr(container.begin() + mid + 1, container.begin() + high);
    //low ~ mid 까지의 배열과 mid + 1~ high 까지의 배열을 차례로 조합해서 정렬한다.
    int i = 0, j = 0;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            *iterLow = leftArr[i++];
        } else {
            *iterLow = rightArr[j++];
        }
        iterLow++;
    }

    while (i < leftSize) {
        *iterLow = leftArr[i++];
		iterLow++;
    }
    while (j < rightSize) {
        *iterLow = rightArr[j++];
		iterLow++;
    }
}

// void PmergeMe::fordJohnsonSortVector(std::vector<int>& mainChain, std::vector<int>&subChain) {
// 	for (unsigned int i=0; i<_jacobsthal_idx.size(); i++) {
		
// 	}
// }

void PmergeMe::sortList(void) {
	std::list<std::pair<int, int> > chains;

	for (unsigned int i=0; i<_before.size(); i += 2) {
		std::pair<int, int> chain(-1, -1);
		chain.first = _before[i];
		if (i+1 < _before.size()) chain.second = _before[i+1];
		if (chain.first < chain.second) std::swap(chain.first, chain.second);
		chains.push_back(chain);
	}
	mergeSortList(chains, chains.size());
	std::list<int> main_chain, sub_chain;
	std::list<std::pair<int, int> >::iterator iter = chains.begin();
	for (; iter!= chains.end(); iter++) {
		main_chain.push_back(iter->first);
		sub_chain.push_back(iter->second);
	}
}

void PmergeMe::mergeSortList(std::list<std::pair<int, int> >& container, int size) {
	
}

