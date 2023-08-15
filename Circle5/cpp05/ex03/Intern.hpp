/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:37:18 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 14:44:35 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	private:
		/* no name, no grade, no unique characteristics  */
	public:
		class WrongFormException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		Intern(void);
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		~Intern(void);

		AForm* makeForm(const std::string& form, const std::string& target) const ;
};

#endif
