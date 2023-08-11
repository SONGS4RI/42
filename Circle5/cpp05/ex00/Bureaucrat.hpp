/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:02:52 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 17:35:11 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
	private:
		const std::string _name;
		unsigned int _grade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char * what() const noexcept override;
		};
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat(void);

		const std::string& getName() const;
		const unsigned int& getGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
