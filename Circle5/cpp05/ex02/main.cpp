/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:21:37 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/14 14:51:08 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat A("A", 1);
	Bureaucrat B("B", 150);

	Form F1("F1", 1, 1);
	Form F2("F2", 150, 150);

	try {
		A.signForm(F1);
		A.signForm(F2);

		// B.signForm(F1);// 사인 불가능
		B.signForm(F2);

	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}