/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:15:44 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 20:23:10 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

#include "AMateria.hpp"

struct MateriaList {
	AMateria* materia;
	MateriaList* next;
};

class Floor {
	private:
		static Floor* _floor;
		MateriaList* _list;
		Floor(void);
	public:
		Floor(const Floor& obj);
		Floor& operator=(const Floor& obj);
		~Floor(void);

		static Floor* getFloor(void);
		void addToList(AMateria* obj);
};

#endif
