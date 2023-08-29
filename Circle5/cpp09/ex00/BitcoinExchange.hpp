/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:27:48 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/29 20:44:41 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <exception>

class BitcoinExchange {
	private:
		static BitcoinExchange* _ptr;
		std::map<std::string, double> _data;
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		~BitcoinExchange(void);
	public:
		class FileOpenException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class InvalidDateException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class InvalidValueException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		static BitcoinExchange* getBitcoinExchange(void);
		void getDataBase(const std::string& filename);
};

#endif
