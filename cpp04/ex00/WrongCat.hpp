/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:47:46 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/04 16:49:16 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    private:
        /* data */
    public:
        WrongCat();
        WrongCat(const WrongCat& obj);
        WrongCat& operator=(const WrongCat& obj);
        ~WrongCat();

        void makeSound() const;
};

#endif
