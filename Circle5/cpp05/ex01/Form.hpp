/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:40:05 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 20:03:42 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _signature;
		const unsigned int _sign_grade;
		const unsigned int _execute_grade;
		Form(void);
	public:
		class GradeTooHighException : public std::exception {
			const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what(void) const throw();
		};
		Form(const std::string& name);
		Form(const std::string& name, const unsigned int& sign_grade,
			const unsigned int& execute_grade);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form(void);

		const std::string& getName(void) const;
		const bool& getSignature(void) const;
		const unsigned int& getSignGrade(void) const;
		const unsigned int& getExecuteGrade(void) const;

		void beSigned(const Bureaucrat& obj);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
