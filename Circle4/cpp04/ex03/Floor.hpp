/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:34:15 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/09 17:17:59 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

#include "AMateria.hpp"

class Floor {
	private:
		AMateria *_materias[8];
		unsigned int _idx;
	public:
		Floor(void);
		Floor(const Floor& obj);
		Floor& operator=(const Floor& obj);
		~Floor(void);

		const AMateria* getMateria(int idx) const;
		void setMaterias(AMateria *obj);
};

#endif
