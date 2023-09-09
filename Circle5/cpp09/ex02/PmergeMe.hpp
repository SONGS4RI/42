/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:25:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/09 16:55:29 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
	private:
		static PmergeMe* _ptr;
		std::vector<int> _before;
		std::vector<int> _after;
		std::pair<int,int> _v_time;
		std::pair<int,int> _dq_time;
		PmergeMe(void);
		PmergeMe(char** argv);
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
	public:
		~PmergeMe(void);
		static PmergeMe* getPmergeMe(char** argv);

		void sortVector(void);
		void recursiveInsertSortVector(std::vector<std::pair<int, int> >& container, int size);
		void fordJohnsonSortVector(std::vector<int>& mainChain, std::vector<int>& subChain);

		void sortDeque(void);
		void recursiveInsertSortDeque(std::deque<std::pair<int, int> >& container, int size);
		void fordJohnsonSortDeque(std::deque<int>& mainChain, std::deque<int>& subChain);
};

#endif
