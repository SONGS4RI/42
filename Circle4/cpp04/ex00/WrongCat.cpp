/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:47:51 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/04 17:50:06 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "default constructor called " << "[WrongCat]" << std::endl;

    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj) {
    std::cout << "Copy constructor called " << "[WrongCat]" << std::endl;
    *this=obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
    std::cout << "Copy assignment operator called " << "[WrongCat]" << std::endl;
    if (this != &obj) {
        _type = obj.getType();
    }
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "Destructor called " << "[WrongCat]" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "meow~~!!" << std::endl;
}