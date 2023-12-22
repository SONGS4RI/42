/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:58:28 by jahlee            #+#    #+#             */
/*   Updated: 2023/12/22 18:48:08 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cmath>

Span::Span() {}

Span::Span(unsigned int n) {
	_n = n;
}

Span::Span(const Span& obj) {
	*this = obj;
}

Span& Span::operator=(const Span& obj) {
	if (this != &obj) {
		_n = obj._n;
		_v = std::vector<int>(obj._v);
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int val) {
	if (_v.size() == _n) {
		throw std::exception();
	}
	_v.push_back(val);
}

unsigned int Span::shortestSpan(void) {
	if (_v.size() <= 1) {
		throw std::exception();
	}
	unsigned int res = longestSpan();
	std::vector<int>::iterator iter = _v.begin() + 1;
	for (; iter != _v.end(); iter++) {
		res = std::min(res, static_cast<unsigned int>(*iter) - *(iter - 1));
	}
	return (res);
}

unsigned int Span::longestSpan(void) {
	if (_v.size() <= 1) throw std::exception();
	std::sort(_v.begin(), _v.end());
	return (static_cast<unsigned int>(_v.back()) - _v.front());
}