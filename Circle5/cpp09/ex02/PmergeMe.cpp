/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:25:08 by jahlee            #+#    #+#             */
/*   Updated: 2024/01/11 19:46:05 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

#define INVALID_INPUT "invalid input"

PmergeMe* PmergeMe::_ptr;
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe() {}

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

void PmergeMe::checkResult() {
	if (_after_vector.size() != _after_list.size()) {
		std::cout << "wrong sorting\n";
		return ;
	}
	std::vector<int>::iterator v = _after_vector.begin();
	std::list<int>::iterator l = _after_list.begin();
	std::vector<int> sorted(_before);
	sort(sorted.begin(), sorted.end());
	for (unsigned int i=0; i<_after_vector.size(); i++) {
		if (v[i] != *(l++) || v[i] != sorted[i]) {
			std::cout << "wrong sorting\n";
			return ;
		}
	}
}

void PmergeMe::sortVector() {
	clock_t startTime = clock();
	std::vector<std::pair<int, int> > chains;
	isValidElements();
	getJacobsthalNumbersVector();
	for (unsigned int i=0; i<_before.size(); i += 2) {
		std::pair<int, int> chain(-1, -1);
		chain.first = _before[i];
		if (i+1 < _before.size()) chain.second = _before[i+1];
		if (chain.first < chain.second) std::swap(chain.first, chain.second);
		chains.push_back(chain);
	}
	mergeInsertionSortVector(chains, 0, chains.size() - 1);
	std::vector<int> main_chain, sub_chain;
	for (unsigned int i=0; i<chains.size(); i++) {
		main_chain.push_back(chains[i].first);
		sub_chain.push_back(chains[i].second);
	}
	main_chain.insert(main_chain.begin(), sub_chain[0]);

	int jacobNum=0, range = 2;
	for (unsigned int i=1; i<_jacob_vector.size(); i++) {
		if (jacobNum < _jacob_vector[i] - 1) {
			jacobNum = _jacob_vector[i] - 1;
			range = range * 2 >= static_cast<int>(main_chain.size()) ? main_chain.size() - 1 : range * 2;
		}
		sortUsingJacobsthalNumberVector(0, range, sub_chain[_jacob_vector[i] - 1], main_chain);
	}
	if (main_chain[0] == -1) {
		main_chain.erase(main_chain.begin());
	}
	_after_vector = main_chain;
	_v_time = (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void PmergeMe::getJacobsthalNumbersVector() {
	unsigned int size = (_before.size() + 1) / 2;
	_jacob_vector.push_back(1);

	std::vector<unsigned int> jacob(2, 1);
	int idx = 2;
	while (jacob[idx-1] + 2 * jacob[idx-2] < size) {
		jacob.push_back(jacob[idx-1] + 2*jacob[idx-2]);
		idx++;
	}
	for (unsigned int i=2; i<jacob.size(); i++) {
		for (unsigned int j=jacob[i]; j>jacob[i-1]; j--) {
			_jacob_vector.push_back(j);
		}
	}
	for (unsigned int i=size; i>jacob.back(); i--) {
		_jacob_vector.push_back(i);
	}
}

void PmergeMe::mergeInsertionSortVector(std::vector<std::pair<int, int> >& container, int low, int high) {
	int mid = (low + high) / 2;
	if (low >= high) return ;
	mergeInsertionSortVector(container, low, mid);
	mergeInsertionSortVector(container, mid + 1, high);
	mergeUsingInsertionVector(container, low, high);
}

void PmergeMe::mergeUsingInsertionVector(std::vector<std::pair<int, int> >& container, int low, int high) {
	int mid = (low + high) / 2;
    int leftSize = mid - low + 1, rightSize = high - mid;
	std::vector<std::pair<int, int> >::iterator iterLow = container.begin() + low;

    std::vector<std::pair<int, int> > leftArr, rightArr;
	for (int i=0; i<leftSize; i++) {
		leftArr.push_back(container[low + i]);
	}
	for (int i=0; i<rightSize; i++) {
		rightArr.push_back(container[mid + 1 + i]);
	}
    int i = 0, j = 0;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            *(iterLow++) = leftArr[i++];
        } else {
            *(iterLow++) = rightArr[j++];
        }
    }
    while (i < leftSize) {
        *(iterLow++) = leftArr[i++];
    }
    while (j < rightSize) {
        *(iterLow++) = rightArr[j++];
    }
}

void PmergeMe::sortUsingJacobsthalNumberVector(int low, int high, int num, std::vector<int>& result) {
	if (low >= high) {
		if (*(result.begin() + low) < num) low++;
		result.insert(result.begin() + low, num);
		return ;
	}
	int mid = (low + high) / 2;
	if (num < *(result.begin() + mid)) {
		sortUsingJacobsthalNumberVector(low, mid - 1, num, result);
	} else {
		sortUsingJacobsthalNumberVector(mid + 1, high, num, result);
	}
}

void PmergeMe::sortList(void) {
	clock_t startTime = clock();
	std::list<std::pair<int, int> > chains;
	isValidElements();
	getJacobsthalNumbersList();

	for (unsigned int i=0; i<_before.size(); i += 2) {
		std::pair<int, int> chain(-1, -1);
		chain.first = _before[i];
		if (i+1 < _before.size()) chain.second = _before[i+1];
		if (chain.first < chain.second) std::swap(chain.first, chain.second);
		chains.push_back(chain);
	}
	mergeInsertionSortList(chains, 0, chains.size() - 1);
	std::list<int> main_chain, sub_chain;
	std::list<std::pair<int, int> >::iterator iter = chains.begin();
	for (; iter != chains.end(); iter++) {
		main_chain.push_back(iter->first);
		sub_chain.push_back(iter->second);
	}
	main_chain.insert(main_chain.begin(), sub_chain.front());
	std::list<int>::iterator jacob = ++_jacob_list.begin();
	int jacobNum = 0, range = 2;
	for (; jacob != _jacob_list.end(); jacob++) {
		if (jacobNum < *jacob - 1) {
			jacobNum = *jacob - 1;
			range = range * 2 >= (int)main_chain.size() ? main_chain.size() - 1 : range * 2;
		}
		std::list<int>::iterator subChainIter = sub_chain.begin();
		for (int i=0; i < *jacob - 1; i++) {
			subChainIter++;
		}
		sortUsingJacobsthalNumberList(0, range, *subChainIter, main_chain);
	}
	if (main_chain.front() == -1) {
		main_chain.pop_front();
	}
	_after_list = main_chain;
	_l_time = (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void PmergeMe::getJacobsthalNumbersList() {
	int size = (_before.size() + 1) / 2;
	_jacob_list.push_back(1);

	std::list<int> jacob(2, 1);
	std::list<int>::iterator iter = jacob.begin();
	while (2 * (*(iter++)) + *(iter--) < size) {
		jacob.push_back(2 * (*iter++) + *(iter));
	}
	iter = jacob.begin()++;
	iter++;
	for (; iter != jacob.end(); iter++) {
		std::list<int>::iterator tmp = iter;
		tmp--;
		for (int j=*iter; j>*tmp; j--) {
			_jacob_list.push_back(j);
		}
	}
	for (int i=size; i>jacob.back(); i--) {
		_jacob_list.push_back(i);
	}
}

void PmergeMe::mergeInsertionSortList(std::list<std::pair<int, int> >& container, int low, int high) {
	int mid = (low + high) / 2;
	if (low >= high) return ;
	mergeInsertionSortList(container, low, mid);
	mergeInsertionSortList(container, mid + 1, high);
	mergeUsingInsertionList(container, low, high);
}

void PmergeMe::mergeUsingInsertionList(std::list<std::pair<int, int> >& container, int low, int high) {
	int mid = (low + high) / 2;
    std::list<std::pair<int, int> > leftArr, rightArr;
	std::list<std::pair<int, int> >::iterator iter = container.begin();
	for (int i=0; i<=high; i++, iter++) {
		if (low <= i && i <= mid) {
			leftArr.push_back(*iter);
		} else if (mid < i) {
			rightArr.push_back(*iter);
		}
	}
	iter = container.begin();
	for (int i=0; i<low; i++) {
		iter++;
	}
	std::list<std::pair<int, int> >::iterator leftIter = leftArr.begin(), rightIter = rightArr.begin();
    while (leftIter != leftArr.end() && rightIter != rightArr.end()) {
        if (*leftIter <= *rightIter) {
            *(iter++) = *(leftIter++);
        } else {
            *(iter++) = *(rightIter++);
        }
    }
    while (leftIter != leftArr.end()) {
        *(iter++) = *(leftIter++);
    }
    while (rightIter != rightArr.end()) {
        *(iter++) = *(rightIter++);
    }
}

void PmergeMe::sortUsingJacobsthalNumberList(int low, int high, int num, std::list<int>& result) {
	std::list<int>::iterator iter = result.begin();
	int mid = (low + high) / 2;
	for (int i=0; i<low; i++) {
		iter++;
	}
	if (low >= high) {
		if (*iter < num) iter++;
		result.insert(iter, num);
		return ;
	}
	for (int i=low; i<mid; i++) {
		iter++;
	}
	if (num < *iter) {
		sortUsingJacobsthalNumberList(low, mid - 1, num, result);
	} else {
		sortUsingJacobsthalNumberList(mid + 1, high, num, result);
	}
}
