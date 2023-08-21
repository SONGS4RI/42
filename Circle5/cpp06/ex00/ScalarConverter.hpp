/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:39 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/21 18:42:03 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define FLOAT_BITS_EXP 0x7F800000
# define FLOAT_BITS_MANTISSA 0x007FFFFF
# define DOUBLE_BITS_EXP 0x7FF0000000000000
# define DOUBLE_BITS_MANTISSA 0x000FFFFFFFFFFFF

#include <string>

enum EType {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_NAN,
	TYPE_INF
};

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter(void);
	public:
		class CanNotConvertException : public std::exception {
			const char* what(void) const throw();
		};
		static EType detectType(const std::string& input);
		static void convert(const std::string& input);

		static void convertToChar(double converted);
		static void convertToInt(double converted);
		static void convertToFloat(double converted);
		static void convertToDouble(double converted);

		
};

#endif
