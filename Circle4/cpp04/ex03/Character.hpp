/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:31:11 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/09 18:56:05 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

struct Floor {
    AMateria *materia;
    Floor* next;
};

class Character : public ICharacter {
    private:
        std::string _name;
        AMateria *_inventory[4];
        Floor* _floor;
        Character(void);
    public:
        Character(const std::string& name);
        Character(const Character& obj);
        Character& operator=(const Character& obj);
        ~Character(void);

        const std::string& getName(void) const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
