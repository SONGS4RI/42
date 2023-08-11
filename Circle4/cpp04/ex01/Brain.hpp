/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:08:59 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/11 15:32:26 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain {
    private:
        std::string _ideas[100];
    public:
        Brain(void);
        Brain(const std::string ideas[100]);
        Brain(const Brain& obj);
        Brain& operator=(const Brain& obj);
        ~Brain(void);

        const std::string* getIdeas(void) const;
};

#endif
