/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/25 20:20:44 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Fixed x1(0.0f), y1(0.0f), z1(0.0f);
	Fixed x2(1.0f), y2(0.0f), z2(0.0f);
	Fixed x3(0.0f), y3(1.0f), z3(0.0f);
	Fixed x4(0.8f), y4(0.1f), z4(0.0f);

	Point a(x1, y1, z1);
	Point b(x2, y2, z2);
	Point c(x3, y3, z3);
	Point p(x4, y4, z4);

	if (bsp(a, b, c, p)) std::cout << "inside" << std::endl;
	else std::cout << "outside" << std::endl;
	return 0;
}