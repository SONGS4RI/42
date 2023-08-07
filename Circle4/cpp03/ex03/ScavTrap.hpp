/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:47:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/31 17:02:26 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : virtual public ClapTrap {
	private:
		unsigned int _scav_hit_point;
		unsigned int _scav_energy_point;
		unsigned int _scav_attack_damage;
		ScavTrap(void);
	protected:
		void setHitPoint(unsigned int amount);
		void setEnergyPoint(unsigned int amount);
		void setAttackDamage(unsigned int amount);
	public:
		ScavTrap(const std::string& name);
		~ScavTrap(void);
		ScavTrap(const ScavTrap& obj);
		ScavTrap& operator=(const ScavTrap& obj);

		void attack(const std::string& target);
		void guardGate(void);

		const unsigned int& getHitPoint(void) const;
		const unsigned int& getEnergyPoint(void) const;
		const unsigned int& getAttackDamage(void) const;
};

#endif