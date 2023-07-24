/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:24:06 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/24 20:41:34 by jahlee           ###   ########.fr       */
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
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& obj);
		Point& operator=(const Point& obj);
		~Point(void);

		const Fixed& getXCoordinate(void) const;
		const Fixed& getYCoordinate(void) const;
};

#endif