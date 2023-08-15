/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:21:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/14 20:27:13 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void leaks() {
	system("leaks ex02");
}

int main() {
	atexit(leaks);
	AForm* form = NULL;
	Bureaucrat* test = NULL;

	try {
		std::cout << "====================test1====================" << std::endl;
		/* ShrubberyCreationForm: Required grades: sign 145, exec 137 */

		// form = new ShrubberyCreationForm("home");
		// test = new Bureaucrat("test", 146);
		// test = new Bureaucrat("test", 145);
		// test = new Bureaucrat("test", 137);
		// test->signForm(*form);
		// test->executeForm(*form);

		// delete form; delete test;
		std::cout << "====================test2====================" << std::endl;
		/* RobotomyRequestForm: Required grades: sign 72, exec 45 */

		// form = new RobotomyRequestForm("jack");
		// test = new Bureaucrat("test", 73);
		// test = new Bureaucrat("test", 72);
		// test = new Bureaucrat("test", 45);
		// test->signForm(*form);
		// test->executeForm(*form);

		// delete form; delete test;
		std::cout << "====================test3====================" << std::endl;
		/* PresidentialPardonForm: Required grades: sign 25, exec 5 */

		// form = new PresidentialPardonForm("daniel");
		// test = new Bureaucrat("test", 26);
		// test = new Bureaucrat("test", 25);
		// test = new Bureaucrat("test", 5);
		// test->signForm(*form);
		// test->executeForm(*form);

		// delete form; delete test;
	} catch (const std::exception* e) {
		std::cout << e->what() << std::endl;
		if (form) delete form;
		if (test) delete test;
		delete e;
	}

	return 0;
}