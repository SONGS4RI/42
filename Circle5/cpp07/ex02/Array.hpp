/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:40:19 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/30 14:08:02 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	private:
		T* _arr;
		unsigned int _size;
	public:
		Array(void) {_size = 0; _arr = new T[0];};
		Array(unsigned int n) {_size = n; _arr = new T[n];};
		Array(const Array& obj) {_arr = NULL; *this = obj;};
		Array& operator=(const Array& obj) {
			if (this != &obj) {
				if (_arr) delete[] _arr;
				_size = obj._size;
				_arr = new T[_size];
				for (unsigned int i = 0; i<obj._size; i++) {
					_arr[i] = obj._arr[i];
				}
			}
			return (*this);
		};
		~Array(void) {delete[] _arr;};

		const unsigned int& size(void) const {return (_size);};
		T& operator[](const unsigned int& idx) {
			if (idx >= _size) throw std::exception();
			return _arr[idx];
		};
};

#endif
