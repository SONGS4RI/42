/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/02 18:16:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(0.0f, 0.0f);
	Point b(1.0f, 0.0f);
	Point c(0.0f, 1.0f);
	Point p(0.1f, 0.1f);

	if (bsp(a, b, c, p)) std::cout << "inside" << std::endl;
	else std::cout << "outside" << std::endl;
	return 0;
}