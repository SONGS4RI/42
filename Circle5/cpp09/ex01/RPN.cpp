/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:18:38 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/01 15:40:45 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "RPN.hpp"

#define WRONG_FORM "Wrong Expression Form"

std::stack<double> RPN::_st;

std::pair<double, double> RPN::getTwoNumsFromTop(void) {
	std::pair<double, double> res;
	if (_st.empty()) throw WRONG_FORM;
	res.second = _st.top();
	_st.pop();
	if (_st.empty()) throw WRONG_FORM;
	res.first = _st.top();
	_st.pop();
	return (res);
}

const double& RPN::calcuateRPN(const std::string& expression) {
	std::string oper = "+-/*";
	int oper_idx;
	std::pair<double, double> nums;
	for (unsigned int i=0; i<expression.size(); i++) {
		if (expression[i] == ' ') continue;
		if (std::isdigit(expression[i])) {
			_st.push(expression[i] - '0');
			continue;
		}
		oper_idx = oper.find(expression[i]);
		switch (oper_idx) {
			case 0 :
				nums = getTwoNumsFromTop();
				_st.push(nums.first + nums.second);
				break;
			case 1 :
				nums = getTwoNumsFromTop();
				_st.push(nums.first - nums.second);
				break;
			case 2 :
				nums = getTwoNumsFromTop();
				_st.push(nums.first / nums.second);
				break;
			case 3 :
				nums = getTwoNumsFromTop();
				_st.push(nums.first * nums.second);
				break;
			default:
				throw WRONG_FORM;
		}
	}
	if (_st.size() != 1) throw WRONG_FORM;
	return _st.top();
}