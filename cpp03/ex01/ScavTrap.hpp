/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:47:16 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/26 20:10:19 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public ClapTrap {
	private:
		ScavTrap(void);
	public:
		ScavTrap(const std::string& name);
		~ScavTrap(void);
		ScavTrap(const ScavTrap& obj);
		ScavTrap& operator=(const ScavTrap& obj);

		void attack(const std::string& target);
};
#endif