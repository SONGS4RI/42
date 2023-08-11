/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:16:39 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 15:38:29 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* _brain;
    public:
        Cat();
        Cat(const std::string ideas[100]);
        Cat(const Cat& obj);
        Cat& operator=(const Cat& obj);
        ~Cat();

        void makeSound() const;
        const Brain& getBrain(void);
};

#endif
