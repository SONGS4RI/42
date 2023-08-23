/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:32:58 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/23 20:07:12 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base {
	public:
		virtual ~Base(void);
		Base* generate(void);
		void identify(Base* p);
		void identify(Base& p);
};

#endif
