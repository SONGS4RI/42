/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:31:11 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/05 17:09:02 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
    private:
        AMateria *_inventory[4];
        std::string _name;
        Character(void);
    public:
        Character(const std::string& name);
        Character(const Character& obj);
        Character& operator=(const Character& obj);
        ~Character(void);

        const std::string& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
