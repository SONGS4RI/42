/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:28:45 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/25 17:33:04 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Point vec_ab = Point::makeVector(a, b);
	Point vec_ac = Point::makeVector(a, c);
	Point vec_ap = Point::makeVector(a, point);

	Fixed res = Point::innerProduct(Point::crossProduct(vec_ab, vec_ac), Point::crossProduct(vec_ab, vec_ap));
	// if (res >= 0) return true;
	// if (bsp(b, c, a, point)) return true;
	return (false);
}