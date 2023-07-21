/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:10:14 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/21 18:22:16 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <iostream>

union Fixed::SharedData {
	int data_i;
	float data_f;
};

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	int sign = num >> 31;

	_value = (num << _bits);
	if (sign) _value = _value | ((sign << _bits) - 1);
}

/*
ex) -5가 들어왔다 생각
고정 소수점
정수부 -5 => 111111111111011, 소수부 => 11111111
*/

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	SharedData data;
	int sign, exponent, inter_fraction, integer_part, fractional_part;

	data.data_f = num;
	sign = data.data_i >> 31;
	exponent = ((data.data_i >> 23) & ((1 << 8) - 1)) - 127;
	inter_fraction = data.data_i & ((1 << 23) - 1);
	if (23 - _bits - exponent > 32) inter_fraction = 0;
	else inter_fraction = ((inter_fraction | (1 << 23)) >> (23 - _bits - exponent));
	fractional_part = inter_fraction & ((1 << _bits) - 1);
	integer_part = inter_fraction >> 8;
	if (sign) {
		integer_part = ~integer_part;
		fractional_part = (~fractional_part & ((1 << _bits) - 1)) + 1;
	}
	_value = (integer_part << _bits) | fractional_part;
}

/*
ex) -0.125가 부동소수점으로 들어온다 생각해보자.

1 01111100 00000000000000000000000 => 부동소수점 표현
부동소수점을 정수부, 소수부로 변환하여 준다.

정수부가 음수이면 (정수부 -1), 소수부를 이진기수법으로 표현해주고 소수부는 반전 + 1을 해준다.
0.001 에대해

111111.11100000 으로 변환된다.

000000000000000.0010000000

*/

Fixed::Fixed(const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		this->_value = obj.getRawBits();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	SharedData data;
	int sign, exponent, inter_fraction, integer_part, fractional_part;

	sign = _value >> 31;
	fractional_part = _value & ((1 << _bits) - 1);
	integer_part = _value >> _bits;
	if (sign) {
		
	}
	//지수 구해야함! 구해서 합쳐주자
	inter_fraction = (integer_part << _bits) | fractional_part;
	//data.data_i = (sign << 31) | ((지수 + 127) << 23) | inter_fraction에서 맨앞하나 때고
	return (data.data_f);
}

/*
float Fixed::toFloat(void) const {
	SharedData data;
	int sign, fixed_point, exponent = -_bits - 1;
	int fractional_part = 1;

	sign = (_value >> 31) & 1;
	fixed_point = _value & (~(1 << 31));
	while (fractional_part <= fixed_point) {
		fractional_part = fractional_part << 1;
		exponent++;
	}

	fractional_part = ((fractional_part >> 1) - 1) & fixed_point;
	data.data_i = (sign << 31) | ((127 + exponent) << 23) | (fractional_part << (23 - (exponent + _bits)));
	return (data.data_f);
}
*/

int Fixed::toInt(void) const {
	return (roundf(toFloat()));
}
