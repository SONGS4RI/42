/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:44:54 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/27 18:43:13 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
class Span {
	private:
		std::vector<int> _v;
		unsigned int _n;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span();

		void addNumber(int val);
		template <typename T>
		void addNumbers(typename T::iterator begin, typename T::iterator end);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
};

#endif