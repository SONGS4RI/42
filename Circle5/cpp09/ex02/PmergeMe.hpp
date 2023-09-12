/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:25:12 by jahlee            #+#    #+#             */
/*   Updated: 2023/09/12 13:47:31 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe {
	private:
		static PmergeMe* _ptr;
		std::vector<int> _before;
		std::vector<int> _after;
		std::vector<int> _jacobsthal_idx;
		std::pair<int,int> _v_time;
		std::pair<int,int> _dq_time;
		PmergeMe(void);
		PmergeMe(char** argv);
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
	public:
		~PmergeMe(void);
		static PmergeMe* getPmergeMe(char** argv);
		void isValidElements(void);
		
		void sortVector(void);
		void recursiveInsertSortVector(std::vector<std::pair<int, int> >& container, int size);
		void fordJohnsonSortVector(std::vector<int>& mainChain, std::vector<int>& subChain);

		void sortList(void);
		void recursiveInsertSortList(std::list<std::pair<int, int> >& container, int size);
		// void fordJohnsonSortList(std::list<int>& mainChain, std::list<int>& subChain);

		const std::vector<int>& getJacobsthalNumbers();
};

#endif
