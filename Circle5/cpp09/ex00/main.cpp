/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:56:33 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/30 17:04:49 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: ./btc [ filename ]" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange* ptr = BitcoinExchange::getBitcoinExchange();
		(void)argv;
		(void)ptr;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
