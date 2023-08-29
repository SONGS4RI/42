/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:01:18 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/29 15:00:19 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	private:
	public:
		MutantStack(void) {};
		MutantStack(const MutantStack& obj) {*this = obj;};
		MutantStack& operator=(const MutantStack& obj) {
			if (this != &obj) {
			}
			return (*this);
		};
		~MutantStack(void) {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) {return (this->c.begin());};
		iterator end(void) {return (this->c.end());};

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void) {return (this->c.rbegin());};
		reverse_iterator rend(void) {return (this->c.rend());};

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator cbegin(void) {return (this->c.cbegin());};
		const_iterator cend(void) {return (this->c.cend());};

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin(void) {return (this->c.cbegin());};
		const_reverse_iterator crend(void) {return (this->c.cend());};

};

#endif
