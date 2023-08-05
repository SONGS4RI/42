/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:20:20 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/05 15:20:21 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "default constructor called " << "[AMateria]" << std::endl;
}

AMateria::AMateria(const AMateria& obj) {
    std::cout << "Copy constructor called " << "[AMateria]" << std::endl;
    *this=obj;
}

AMateria& AMateria::operator=(const AMateria& obj) {
    std::cout << "Copy assignment operator called " << "[AMateria]" << std::endl;
    if (this != &obj) {
        
    }
    return (*this);
}

AMateria::~AMateria() {
    std::cout << "Destructor called " << "[AMateria]" << std::endl;
}
