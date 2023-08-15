/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:02:52 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/14 16:58:22 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		unsigned int _grade;
		Bureaucrat(void);
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();// 예외를 throw 하지 않는다.
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat(void);

		const std::string& getName(void) const;
		const unsigned int& getGrade(void) const;

		void increaseGrade(void);
		void decreaseGrade(void);

		void signForm(AForm& obj);
		void executeForm(const AForm& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
