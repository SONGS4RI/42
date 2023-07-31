/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:28:48 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 19:17:05 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

Point::Point() : _x(Fixed()), _y(Fixed()), _z(Fixed()) {
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)), _z(Fixed()) {
	// std::cout << "Default constructor(const float x,y parameters) called" << std::endl;

}

Point::Point(const Fixed& x, const Fixed& y, const Fixed& z) : _x(x), _y(y), _z(z) {
	// std::cout << "Default constructor(const float x,y,z parameters) called" << std::endl;

}

Point::Point(const Point& obj) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Point& Point::operator=(const Point& obj) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		const_cast<Fixed&>(_x) = obj.getXCoordinate();
		const_cast<Fixed&>(_y) = obj.getYCoordinate();
		const_cast<Fixed&>(_z) = obj.getZCoordinate();
	}
	return (*this);
}

Point::~Point() {
	// std::cout << "Destructor called" << std::endl;
}

const Fixed& Point::getXCoordinate() const {
	return (_x);
}

const Fixed& Point::getYCoordinate() const {
	return (_y);
}

const Fixed& Point::getZCoordinate() const {
	return (_z);
}

Point Point::makeVector(const Point& a, const Point& b) {
	Fixed vec_x(b.getXCoordinate().toFloat() - a.getXCoordinate().toFloat());
	Fixed vec_y(b.getYCoordinate().toFloat() - a.getYCoordinate().toFloat());
	Fixed vec_z(b.getZCoordinate().toFloat() - a.getZCoordinate().toFloat());
	Point vec(vec_x, vec_y, vec_z);
	return (vec);
}

/*
	벡터의 내적
	v1∙v2 = x1x2 + y1y2 + z1z2(제2 코사인 법칙을 사용한 증명)
*/
Fixed Point::innerProduct(const Point& vec_a, const Point& vec_b) {
	Fixed x1(vec_a.getXCoordinate()), y1(vec_a.getYCoordinate()), z1(vec_a.getZCoordinate());
	Fixed x2(vec_b.getXCoordinate()), y2(vec_b.getYCoordinate()), z2(vec_b.getZCoordinate());
	Fixed res(x1*x2 + y1*y2 + z1*z2);
	return (res);
}

/*
	벡터의 외적
	v1☓v2 = | i  j  k  |
			| x1 y1 z1 |
			| x2 y2 z2 |
	v1☓v2 = (y1z2 - z1y2, z1x2 - x1z2, x1y2 - y1x2)
	외적은 항상 두벡터에 수직인 벡터로 나오게되는데 클래스 구조상 2차원 평면에서의 클래스이므로
	반환할때는 _x => x,y(둘다 0 임) _y => z로 생각하고 넘겨준다.
*/
Point Point::crossProduct(const Point& vec_a, const Point& vec_b) {
	Fixed x1(vec_a.getXCoordinate()), y1(vec_a.getYCoordinate()), z1(vec_a.getZCoordinate());
	Fixed x2(vec_b.getXCoordinate()), y2(vec_b.getYCoordinate()), z2(vec_b.getZCoordinate());
	Fixed y1z2(y1*z2), z1y2(z1*y2), z1x2(z1*x2), x1z2(x1*z2), x1y2(x1*y2), y1x2(y1*x2);
	Point res((y1z2 - z1y2), (z1x2 - x1z2), (x1y2 - y1x2));
	return (res);
}

