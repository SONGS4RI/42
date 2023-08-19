/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:21:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/19 14:17:20 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
void leaks() {
	system("leaks $PPID");
}

int main() {
	atexit(leaks);
	AForm* form1 = NULL;
	AForm* form2 = NULL;
	AForm* form3 = NULL;
	AForm* form4 = NULL;
	Bureaucrat* test = NULL;
	Intern someRandomIntern;

	try {
		form1 = someRandomIntern.makeForm("shrubbery creation", "home");
		form2 = someRandomIntern.makeForm("robotomy request", "daniel");
		form3 = someRandomIntern.makeForm("presidential pardon", "jack");
		// form4 = someRandomIntern.makeForm("wrong form", "home");

		test = new Bureaucrat("test", 137);

		std::cout << "====================test1====================" << std::endl;
		test->signForm(*form1);
		test->executeForm(*form1);
		std::cout << "====================test2====================" << std::endl;
		test->signForm(*form2);
		test->executeForm(*form2);
		std::cout << "====================test3====================" << std::endl;
		test->signForm(*form3);
		test->executeForm(*form3);

	} catch (const std::exception* e) {
		std::cout << e->what() << std::endl;
		delete e;
	}

	if (form1) delete form1;
	if (form2) delete form2;
	if (form3) delete form3;
	if (form4) delete form4;
	if (test) delete test;
	return 0;
}