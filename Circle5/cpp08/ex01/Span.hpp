/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:44:54 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/29 14:26:21 by jahlee           ###   ########.fr       */
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
		void addNumbers(typename T::iterator begin, typename T::iterator end) {
			if (_v.size() + std::distance(begin, end) > _n) throw std::exception();
			_v.insert(_v.end(), begin, end);
		}
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
};

#endif