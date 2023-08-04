/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:08:59 by jahlee            #+#    #+#             */
/*   Updated: 2023/08/04 18:32:39 by jahlee           ###   ########.fr       */
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
        Brain(const Brain& obj);
        Brain& operator=(const Brain& obj);
        ~Brain(void);

        const std::string* getIdeas(void) const;
        void setIdeas(const std::string ideas[100]);
};

#endif
