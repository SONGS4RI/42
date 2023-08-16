/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:39 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/16 20:11:43 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter(void);
	public:
		static void convert(std::string input);
		static void convertToChar(std::string input);
		static void convertToInt(std::string input);
		static void convertToFloat(std::string input);
		static void convertToDouble(std::string input);
};

#endif
