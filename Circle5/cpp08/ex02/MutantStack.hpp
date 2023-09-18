/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:01:18 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/18 17:10:24 by jahlee           ###   ########.fr       */
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
				this->c = obj.c;
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
		const_iterator begin(void) const {return (this->c.begin());};
		const_iterator end(void) const {return (this->c.end());};
		const_iterator cbegin(void) const {return (this->c.cbegin());};
		const_iterator cend(void) const {return (this->c.cend());};

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin(void) const {return (this->c.cbegin());};
		const_reverse_iterator crend(void) const {return (this->c.cend());};
		const_reverse_iterator rbegin(void) const {return (this->c.rbegin());};
		const_reverse_iterator rend(void) const {return (this->c.rend());};
};

#endif
