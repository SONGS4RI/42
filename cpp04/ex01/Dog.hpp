/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:10:20 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/04 15:24:25 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	private:

	public:
		Dog();
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		~Dog();

		void makeSound() const;
};

#endif
