/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:28:48 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/24 20:51:26 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

Point::Point() {
	std::cout << "Default constructor called" << std::endl;

	_x = Fixed();
	_y = Fixed();
}

Point::Point(const float x, const float y) {
	std::cout << "Default constructor(const float parameters) called" << std::endl;

	_x = Fixed(x);
	_y = Fixed(y);
}

Point::Point(const Point& obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Point& Point::operator=(const Point& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		this->_x = obj.getXCoordinate();
		this->_y = obj.getYCoordinate();
	}
	return (*this);
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

const Fixed& Point::getXCoordinate() const {
	return (_x);
}

const Fixed& Point::getYCoordinate() const {
	return (_y);
}