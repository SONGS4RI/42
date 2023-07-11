/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:02:57 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/11 19:50:32 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed {
	private:
		int _value;
		static const int _bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};