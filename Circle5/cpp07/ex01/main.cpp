/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:10:21 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/30 14:22:24 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void printSomething(const T& t) {
	std::cout << t << std::endl;
}

int main( void ) {
	int n = 5;
	int arr_i[n];
	char arr_c[n];

	for (int i=0; i<n; i++) {
		arr_i[i] = i;
		arr_c[i] = i + 'a';
	}
	std::cout << "==================test1==================\n";
	iter(arr_i, n, printSomething<int>);
	std::cout << "==================test2==================\n";
	iter(arr_c, n, printSomething<char>);
	return 0;
}