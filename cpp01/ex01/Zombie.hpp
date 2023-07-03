/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:18:47 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/03 20:26:07 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		std::string getName(void) const;
		void setZombieName(std::string name);
		Zombie();
		~Zombie(void);
		void	announce(void);
};
