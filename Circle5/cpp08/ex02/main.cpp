/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:41:40 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/18 17:12:09 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
	{
		std::cout << "====================test 1====================" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;// 17 5
		mstack.pop();// 5
		std::cout << mstack.size() << std::endl;
		mstack.push(3);// 3 5
		mstack.push(5);// 5 3 5
		mstack.push(737);// 737 5 3 5
		mstack.push(0);// 0 737 5 3 5
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "====================test 2====================" << std::endl;
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(list);
	}
	{
		std::cout << "====================test 3====================" << std::endl;
		MutantStack<int> mstack1;// 3 2 1
		MutantStack<int> mstack2;// 1 2 3
		mstack1.push(1);
		mstack1.push(2);
		mstack1.push(3);
		mstack2.push(3);
		mstack2.push(2);
		mstack2.push(1);
		for (MutantStack<int>::iterator iter = mstack2.begin(); iter != mstack2.end(); iter++) {
			std::cout << *iter << " ";
		}
		std::cout << "\n";
		mstack2 = mstack1;
		for (MutantStack<int>::iterator iter = mstack2.begin(); iter != mstack2.end(); iter++) {
			std::cout << *iter << " ";
		}
		std::cout << "\n";
	}
	return (0);
}