/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:31:11 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/09 17:00:16 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"

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
