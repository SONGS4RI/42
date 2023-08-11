/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:09:11 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 15:34:33 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain() {
    std::cout << "default constructor called " << "[Brain]" << std::endl;
}

Brain::Brain(const std::string ideas[100]) {
    std::cout << "default constructor called " << "[Brain]" << std::endl;

    for (int i=0; i<100; i++) {
        _ideas[i] = ideas[i];
    }
}

Brain::Brain(const Brain& obj) {
    std::cout << "Copy constructor called " << "[Brain]" << std::endl;
    *this=obj;
}

Brain& Brain::operator=(const Brain& obj) {
    std::cout << "Copy assignment operator called " << "[Brain]" << std::endl;
    if (this != &obj) {
        for (int i=0; i<100; i++) {
            _ideas[i] = obj._ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "Destructor called " << "[Brain]" << std::endl;
}

const std::string* Brain::getIdeas() const {
    return (_ideas);
}

