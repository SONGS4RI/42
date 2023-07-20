/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:02:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/20 20:43:46 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _bits = 8;
	public:
		union SharedData;
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed(void);

		void setRawBits(int const raw);
		int getRawBits(void) const;
		float toFloat(void) const;// converts the fixed-point value to a floating-point value.
		int toInt(void) const;// converts the fixed-point value to an integer value.
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
