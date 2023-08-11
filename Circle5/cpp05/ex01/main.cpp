/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:21:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 20:52:28 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat A("A", 1);
		Bureaucrat B("B", 150);

		Form F1("1", 1, 1);
		Form F2("150", 150, 150);

		A.signForm(F1);
		A.signForm(F2);

		B.signForm(F1);
		B.signForm(F2);

	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}