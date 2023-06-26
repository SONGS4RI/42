/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:31:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/26 16:39:28 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_HPP
# define ENUM_HPP

enum eMessage {
	PROMPT,
	ADD,
	SEARCH,
	EXIT,
	WRONG_COMMAND,
	WRONG_CONTACT_INFO,
	EMPTY,
	WRONG_IDX,
	WRONG_IDX_RANGE,
};

enum eContact {
	FIRST_NAME,
	LAST_NAME,
	NICK_NAME,
	PHONE_NUMBER,
	DARKEDST_SECRET
};
#endif