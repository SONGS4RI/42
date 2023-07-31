/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:24:05 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 17:04:11 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : virtual public ClapTrap {
	private:
		unsigned int _frag_hit_point;
		unsigned int _frag_energy_point;
		unsigned int _frag_attack_damage;
		FragTrap();
	protected:
		void setHitPoint(unsigned int amount);
		void setEnergyPoint(unsigned int amount);
		void setAttackDamage(unsigned int amount);
	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& obj);
		FragTrap& operator=(const FragTrap& obj);
		~FragTrap();

		void highFivesGuys(void);

		const unsigned int& getHitPoint(void) const;
		const unsigned int& getEnergyPoint(void) const;
		const unsigned int& getAttackDamage(void) const;
};

#endif