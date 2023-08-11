/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:10:20 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 15:37:39 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* _brain;
	public:
		Dog(void);
		Dog(const std::string ideas[100]);
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		~Dog(void);

		void makeSound(void) const;
		const Brain& getBrain(void);
};

#endif
