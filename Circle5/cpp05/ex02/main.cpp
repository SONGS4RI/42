/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:21:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/19 14:16:04 by jahlee           ###   ########.fr       */
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
	AForm* form1 = NULL;
	AForm* form2 = NULL;
	AForm* form3 = NULL;
	Bureaucrat* test = NULL;

	try {

		// test = new Bureaucrat("test", 146);
		// test = new Bureaucrat("test", 145);
		// test = new Bureaucrat("test", 137);
		// test = new Bureaucrat("test", 73);
		// test = new Bureaucrat("test", 72);
		// test = new Bureaucrat("test", 45);
		// test = new Bureaucrat("test", 26);
		// test = new Bureaucrat("test", 25);
		// test = new Bureaucrat("test", 5);


		std::cout << "====================test1====================" << std::endl;
		/* ShrubberyCreationForm: Required grades: sign 145, exec 137 */
		form1 = new ShrubberyCreationForm("home");
		test->signForm(*form1);
		test->executeForm(*form1);

		std::cout << "====================test2====================" << std::endl;
		/* RobotomyRequestForm: Required grades: sign 72, exec 45 */

		form2 = new RobotomyRequestForm("jack");
		test->signForm(*form2);
		test->executeForm(*form2);

		std::cout << "====================test3====================" << std::endl;
		/* PresidentialPardonForm: Required grades: sign 25, exec 5 */

		form3 = new PresidentialPardonForm("daniel");
		test->signForm(*form3);
		test->executeForm(*form3);

	} catch (const std::exception* e) {
		std::cout << e->what() << std::endl;
		delete e;
	}

	if (form1) delete form1;
	if (form2) delete form2;
	if (form3) delete form3;
	if (test) delete test;

	return 0;
}