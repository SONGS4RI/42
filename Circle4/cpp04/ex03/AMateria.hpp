/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:20:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/07 19:39:00 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
    private:
        std::string _type;
        AMateria(void);
    protected:
        void setType(std::string const & type);
    public:
        AMateria(std::string const & type);
        AMateria(const AMateria& obj);
        AMateria& operator=(const AMateria& obj);
        virtual ~AMateria(void);

        const std::string& getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif

