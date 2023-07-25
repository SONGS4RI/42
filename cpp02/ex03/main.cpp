/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/25 16:13:46 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

int main( void ) {
	Fixed x1(1.0f), y1(0.0f), z1(0.0f);
	Fixed x2(0.0f), y2(1.0f), z2(0.0f);

	Point a(x1, y1, z1);
	Point b(x2, y2, z2);

	// Point vec_a = a.makeVector

	Point cross_ab = Point::crossProduct(a, b);
	Fixed inner_ab = Point::innerProduct(a, b);
	std::cout  << cross_ab.getXCoordinate() << " " << cross_ab.getYCoordinate() << " " << cross_ab.getZCoordinate() << std::endl;
	std::cout  << inner_ab << std::endl;
	return 0;
}