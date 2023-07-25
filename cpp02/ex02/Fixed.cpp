/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:10:14 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/25 20:54:17 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "./Fixed.hpp"

union Fixed::SharedData {
	int data_i;
	float data_f;
};

int Fixed::floatToFixed(const float num) {
	SharedData data;
	int sign, exponent, inter_fraction, integer_part, fractional_part;

	fractional_part = 1 << _bits;
	data.data_f = roundf(num * fractional_part) / fractional_part;
	sign = data.data_i >> 31;
	exponent = ((data.data_i >> 23) & ((1 << 8) - 1)) - 127;
	inter_fraction = data.data_i & ((1 << 23) - 1);
	if (23 - _bits - exponent > 32) inter_fraction = 0;
	else inter_fraction = ((inter_fraction | (1 << 23)) >> (23 - _bits - exponent));
	fractional_part = inter_fraction & ((1 << _bits) - 1);
	integer_part = inter_fraction >> 8;
	if (sign) {
		integer_part = ~integer_part;
		fractional_part = ~fractional_part & ((1 << _bits) - 1);
	}
	return ((integer_part << _bits) | fractional_part);
}

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	int sign = num >> 31;
	if (sign) {
		_value = ~((~num + 1) << _bits);
	} else {
		_value = (num << _bits);
	}
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	_value = floatToFixed(num);
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

bool Fixed::operator>(const Fixed& obj) const {
	return (this->_value > obj.getRawBits());
}

bool Fixed::operator<(const Fixed& obj) const {
	return (this->_value < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed& obj) const {
	return (this->_value >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed& obj) const {
	return (this->_value <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed& obj) const {
	return (this->_value == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed& obj) const {
	return (this->_value != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed& obj) const {
	Fixed res(this->toFloat() + obj.toFloat());
	return (res);
}

Fixed Fixed::operator-(const Fixed& obj) const {
	Fixed res(this->toFloat() - obj.toFloat());
	return (res);
}

Fixed Fixed::operator*(const Fixed& obj) const {
	Fixed res(this->toFloat() * obj.toFloat());
	return (res);
}

Fixed Fixed::operator/(const Fixed& obj) const {
	Fixed res(this->toFloat() / obj.toFloat());
	return (res);
}

Fixed& Fixed::operator++() {
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(toFloat());
	this->_value++;
	return (tmp);
}

Fixed& Fixed::operator--() {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(toFloat());
	this->_value--;
	return (tmp);
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
	inter_fraction = (integer_part << _bits) | fractional_part;
	if (sign) {
		inter_fraction = ~inter_fraction;
	}
	exponent = -_bits - 1; fractional_part = 1;
	while (fractional_part <= inter_fraction) {
		fractional_part = fractional_part << 1;
		exponent++;
	}
	if (exponent == -_bits - 1) {
		exponent = -127;
		fractional_part = 0;
	} else {
		fractional_part = (((fractional_part >> 1) - 1) & inter_fraction) << (23 - _bits - exponent);
	}

	data.data_i = sign << 31 | ((127 + exponent) << 23) | fractional_part;
	return (data.data_f);
}

int Fixed::toInt(void) const {
	return (roundf(toFloat()));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}
