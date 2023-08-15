/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:11:54 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 19:13:37 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	private:

	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		virtual ~Animal(void);

		const std::string& getType(void) const;
		virtual void makeSound() const = 0;
};

#endif