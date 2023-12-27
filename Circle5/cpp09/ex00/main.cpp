/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:56:33 by jahlee            #+#    #+#             */
/*   Updated: 2023/12/22 19:09:42 by jahlee           ###   ########.fr       */
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
		BitcoinExchange* btc = BitcoinExchange::getBitcoinExchange();
		btc->calculateInputs(argv[1]);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		delete BitcoinExchange::getBitcoinExchange();
		return (1);
	}
	delete BitcoinExchange::getBitcoinExchange();
	return (0);
}
