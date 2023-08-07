/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:56:30 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/07 19:27:30 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	private:
		/* data */
	public:
		Ice(void);
		Ice(const Ice& obj);
		Ice& operator=(const Ice& obj);
		~Ice(void);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
