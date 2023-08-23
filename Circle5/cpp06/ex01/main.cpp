/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:09:13 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/23 19:28:18 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data data;
	std::cout << std::setw(20) << std::left << "data address: " << &data << std::endl;
	std::cout << std::setw(20) << std::left << "data serialized: " << Serializer::serialize(&data) << std::endl;
	std::cout << std::setw(20) << std::left << "data deserialize: " << Serializer::deserialize(Serializer::serialize(&data)) << std::endl;
	return (0);
}