/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:41:40 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/27 16:39:47 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
	int n = 10;

	try {
		std::vector<int> v;
		std::list<int> l;
		std::deque<int> dq;
		for (int i=0; i<n; i++) {
			v.push_back(i);
			l.push_back(i);
			dq.push_back(i);
		}
		std::cout << "==================test vector==================" << std::endl;
		std::cout << *easyfind(v, 2) << std::endl;
		std::cout << "==================test list==================" << std::endl;
		std::cout << *easyfind(l, 5) << std::endl;
		std::cout << "==================test deque==================" << std::endl;
		std::cout << *easyfind(dq, 9) << std::endl;
		std::cout << "==================test exception==================" << std::endl;
		std::cout << *easyfind(dq, 10) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}