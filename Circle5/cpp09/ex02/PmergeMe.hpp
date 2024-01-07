/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:25:12 by jahlee            #+#    #+#             */
/*   Updated: 2024/01/07 19:53:52 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
// #include <cstdlib>
#include <ctime>

class PmergeMe {
	private:
		static PmergeMe* _ptr;
		std::vector<int> _before;
		std::vector<int> _jacobsthal_idx;
		PmergeMe(void);
		PmergeMe(char** argv);
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		
		void getJacobsthalNumbers();
		void isValidElements(void);

		void mergeUsingInsertionVector(std::vector<std::pair<int, int> >& container, int low, int high);
		void sortUsingJacobsthalNumberVector(int low, int high, int num, std::vector<int>& result);

		void mergeSortList(std::list<std::pair<int, int> >& container, int size);
		// void fordJohnsonSortList(std::list<int>& mainChain, std::list<int>& subChain);
	public:
		~PmergeMe(void);
		std::vector<int> _after_vector;
		std::vector<int> _after_list;
		double _v_time;
		double _list_time;
		void mergeInsertionSortVector(std::vector<std::pair<int, int> >& container, int low, int high);
		static PmergeMe* getPmergeMe(char** argv);
		void sortVector(void);
		void sortList(void);
		std::vector<int> getAfter();
};

#endif
