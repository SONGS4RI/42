/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:01:27 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/01 16:15:26 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>

class RPN {
	private:
		static std::stack<double> _st;
		RPN(void);
		RPN(const RPN& obj);
		RPN& operator=(const RPN& obj);
		~RPN(void);
		static std::pair<double, double> getTwoNumsFromTop(void);
	public:
		static const double& calcuateRPN(const std::string& expression);
};

#endif
