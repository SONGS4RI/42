/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:01:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/07 19:03:30 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	private:
		/* data */
	public:
		Cure(void);
		Cure(const Cure& obj);
		Cure& operator=(const Cure& obj);
		~Cure(void);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
