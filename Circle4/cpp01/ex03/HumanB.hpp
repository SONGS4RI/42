/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:06:55 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/04 15:23:53 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "./Weapon.hpp"

class HumanB {
	private:
		Weapon* _weapon;
		std::string _name;
	public:
		const std::string& getName(void);
		void setName(std::string name);
		void attack(void);
		void setWeapon(Weapon& weapon);
		HumanB(std::string name);
		~HumanB(void);
};

#endif