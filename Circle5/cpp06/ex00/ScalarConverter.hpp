/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:39 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/16 16:25:36 by jahlee           ###   ########.fr       */
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
};

#endif