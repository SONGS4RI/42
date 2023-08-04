/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:11:54 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/04 14:35:14 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
	private:

	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		~Animal(void);

		const std::string& getType(void) const;
};

#endif