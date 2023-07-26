/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:42:24 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/26 19:27:23 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap {
	private:
		std::string _name;
		unsigned int _hit_point;
		unsigned int _energy_point;
		unsigned int _attack_damage;
	protected:
		void setName(std::string name);
		void setHitPoint(unsigned int amount);
		void setEnergyPoint(unsigned int amount);
		void setAttackDamage(unsigned int amount);
	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		~ClapTrap();
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator=(const ClapTrap& obj);

		const std::string& getName(void) const;
		const unsigned int& getHitPoint(void) const;
		const unsigned int& getEnergyPoint(void) const;
		const unsigned int& getAttackDamage(void) const;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif