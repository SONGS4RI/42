/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/25 20:26:01 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

/*
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/

// int main() {
// 	Fixed a(42);
// 	Fixed b(4.2f);

// 	std::cout << a + b << std::endl;
// 	std::cout << a - b << std::endl;
// 	std::cout << a * b << std::endl;
// 	std::cout << a / b << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// }
