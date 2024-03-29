/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:40:05 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/14 20:01:35 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string _name;
		bool _signature;
		const unsigned int _sign_grade;
		const unsigned int _execute_grade;
		AForm(void);
	public:
		class GradeTooHighException : public std::exception {
			const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what(void) const throw();
		};
		class NotSignedException : public std::exception {
			const char* what(void) const throw();
		};
		class SystemErrorException : public std::exception {
			const char* what(void) const throw();
		};
		AForm(const std::string& name);
		AForm(const std::string& name, const unsigned int& sign_grade,
			const unsigned int& execute_grade);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm(void);

		const std::string& getName(void) const;
		const bool& getSignature(void) const;
		const unsigned int& getSignGrade(void) const;
		const unsigned int& getExecuteGrade(void) const;

		void checkExecutable(const Bureaucrat& executor) const;

		virtual void beSigned(const Bureaucrat& obj);
		virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
