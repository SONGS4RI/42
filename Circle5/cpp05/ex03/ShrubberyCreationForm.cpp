/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:00:34 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/14 19:59:28 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
				AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Default constructor called " << "[ShrubberyCreationForm]" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj){
	std::cout << "Copy constructor called " << "[ShrubberyCreationForm]" << std::endl;

	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	std::cout << "Copy assignment operator called " << "[ShrubberyCreationForm]" << std::endl;
	if (this != &obj) {
		_target = obj._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor called " << "[ShrubberyCreationForm]" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	try {
		checkExecutable(executor);
	} catch (const std::exception* e) {
		throw (e);
	}

	std::ofstream ofs((_target + "_shrubbery").c_str(), std::ios::trunc);
	if (ofs.fail()) throw new SystemErrorException();

	std::cout << executor.getName() << " executed " << getName() << std::endl;

	ofs
	<< "       (    .        +          .      .          ." << std::endl
	<< "    ( .            _        .       +            ." << std::endl
	<< "  ,    +         /;-._,-.____        ,-----.__" << std::endl
	<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl
	<< "  `     +           \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl
	<< "  (           +       ,    `./  \\:. `.   )==-\'  ." << std::endl
	<< "   \\.      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl
	<< ".   (       \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl
	<< "     \\ .    /:+- - + +- : :- + + -:\'  /(o-) \\)     ." << std::endl
	<< "  .    (  ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl
	<< "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl
	<< "              \\:  `  X` _| _,\\/'   .-'" << std::endl
	<< ".               \":._:`\\____  /:'  /      .           ." << std::endl
	<< "                    \\::.  :\\/:'  /              +" << std::endl
	<< "   .                 `.:.  /:'  }      ." << std::endl
	<< "           .           ):_(:;   \\           ." << std::endl
	<< "                      /:. _/ ,  |" << std::endl
	<< "                   . /(|::.     ,`                  ." << std::endl
	<< "     .                |::.    {\\" << std::endl
	<< "                      |::.\\  \\ `." << std::endl
	<< "                      |:::(\\    |" << std::endl
	<< "              O       |:::/{ }  |                  (o" << std::endl
	<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl
	<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;

	ofs.close();
}
