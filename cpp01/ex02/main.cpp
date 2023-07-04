/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:12:50 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/04 13:27:17 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *strPtr = &str;
	std::string& strRef = str;

	std::cout << &str << std::endl;
	std::cout << strPtr << std::endl;
	std::cout << &strRef << std::endl;

	std::cout << str << std::endl;
	std::cout << *strPtr << std::endl;
	std::cout << strRef << std::endl;
}