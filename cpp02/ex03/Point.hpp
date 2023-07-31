/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:24:06 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 18:57:15 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "./Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
		const Fixed _z;
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
		static Point makeVector(const Point& a, const Point& b);
		static Fixed innerProduct(const Point& vec_a, const Point& vec_b);
		static Point crossProduct(const Point& vec_a, const Point& vec_b);
};

#endif