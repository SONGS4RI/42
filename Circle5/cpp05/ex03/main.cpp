/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:21:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/15 16:19:01 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
void leaks() {
	system("leaks ex03");
}

int main() {
	atexit(leaks);
	AForm* form = NULL;
	Bureaucrat* test = NULL;
	Intern someRandomIntern;
	try {
		std::cout << "====================test1====================" << std::endl;
		/* ShrubberyCreationForm: Required grades: sign 145, exec 137 */

		form = someRandomIntern.makeForm("shrubbery creation", "home");
		// test = new Bureaucrat("test", 146);
		// test = new Bureaucrat("test", 145);
		test = new Bureaucrat("test", 137);
		test->signForm(*form);
		test->executeForm(*form);

		if (form) delete form; form = NULL;
		if (test) delete test; test = NULL;
		std::cout << "====================test2====================" << std::endl;
		/* RobotomyRequestForm: Required grades: sign 72, exec 45 */

		form = someRandomIntern.makeForm("robotomy request", "jack");
		test = new Bureaucrat("test", 73);
		// test = new Bureaucrat("test", 72);
		// test = new Bureaucrat("test", 45);
		// test->signForm(*form);
		// test->executeForm(*form);

		if (form) delete form; form = NULL;
		if (test) delete test; test = NULL;
		std::cout << "====================test3====================" << std::endl;
		/* PresidentialPardonForm: Required grades: sign 25, exec 5 */

		form = someRandomIntern.makeForm("presidential pardon", "daniel");
		test = new Bureaucrat("test", 26);
		// test = new Bureaucrat("test", 25);
		// test = new Bureaucrat("test", 5);
		// test->signForm(*form);
		// test->executeForm(*form);

		if (form) delete form; form = NULL;
		if (test) delete test; test = NULL;
	} catch (const std::exception* e) {
		std::cout << e->what() << std::endl;
		if (form) delete form;
		if (test) delete test;
		delete e;
	}

	return 0;
}