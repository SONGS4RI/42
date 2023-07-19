/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:10:14 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/19 19:25:25 by jahlee           ###   ########.fr       */
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
	int sign = ((num >> 31) & 1) << 31;
	if (sign) {// 2보수를 처리해주어야 한다.
		_value = (~num + 1) << _bits;
	} else {
		_value = num << _bits;
	}
	_value = sign | _value;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	SharedData data;
	data.data_f = num;
	int sign, exponent, fractional_part;
	sign = ((data.data_i >> 31) & 1) << 31;
	exponent = (data.data_i >> 23) & ((1 << 8) - 1) - 127;
	fractional_part = data.data_i & ((1 << 23) - 1);
	_value = sign | ((fractional_part | (1 << 23)) >> (23 - _bits - exponent));
}

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

Fixed& Fixed::operator<<(const Fixed& obj) {
	// std::cout << obj.toFloat() << std::endl;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	SharedData data;
	int sign, fixed_point, exponent = 0;
	int compare_bit = 1 << _bits;

	sign = ((_value >> 31) & 1) << 31;
	fixed_point = (_value << 1) >> 1;

	exponent = -8;
	while (compare_bit <= fixed_point) {
		compare_bit = compare_bit << 1;
		exponent++;
	}
	exponent--;
	// exponent += 127;//지수에 bias 더해준다.
	// data.data_i = sign | (exponent << 23);// | 소수부;
}

int Fixed::toInt(void) const {
	
}