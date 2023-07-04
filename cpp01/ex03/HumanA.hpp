/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:06:55 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/04 16:01:33 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "./Weapon.hpp"

class HumanA {
	private:
		Weapon& _weapon;
		std::string _name;
	public:
		const std::string& getName(void);
		void setName(std::string name);
		void attack(void);
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
};

#endif