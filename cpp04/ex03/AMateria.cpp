/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:20:20 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/05 16:54:14 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(const AMateria& obj) {
    std::cout << "Copy constructor called " << "[AMateria]" << std::endl;
    *this=obj;
}

AMateria& AMateria::operator=(const AMateria& obj) {
    std::cout << "Copy assignment operator called " << "[AMateria]" << std::endl;
    if (this != &obj) {
        _type = obj.getType();
    }
    return (*this);
}

AMateria::~AMateria() {
    std::cout << "Destructor called " << "[AMateria]" << std::endl;
}

AMateria::AMateria(std::string const & type) {
    std::cout << "default constructor called " << "[AMateria]" << std::endl;

    _type = type;
}

void AMateria::setType(std::string const & type) {
    _type = type;
}