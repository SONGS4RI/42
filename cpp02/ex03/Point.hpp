/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:24:06 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/25 15:37:48 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "./Fixed.hpp"

class Point
{
	private:
		Fixed _x;
		Fixed _y;
		Fixed _z;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Fixed& x, const Fixed& y, const Fixed& z);
		Point(const Point& obj);
		Point& operator=(const Point& obj);
		~Point(void);

		const Fixed& getXCoordinate(void) const;
		const Fixed& getYCoordinate(void) const;
		const Fixed& getZCoordinate(void) const;
		Point makeVector(const Point& a, const Point& b) const;
		static Fixed innerProduct(const Point& vec_a, const Point& vec_b);
		static Point crossProduct(const Point& vec_a, const Point& vec_b);
};

#endif