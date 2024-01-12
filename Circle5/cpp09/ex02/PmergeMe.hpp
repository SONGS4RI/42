/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:25:12 by jahlee            #+#    #+#             */
/*   Updated: 2024/01/09 20:11:44 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <ctime>
#include <algorithm>

class PmergeMe {
	private:
		static PmergeMe* _ptr;
		std::vector<int> _jacob_vector;
		std::list<int> _jacob_list;
		PmergeMe(void);
		PmergeMe(char** argv);
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);

		void isValidElements(void);

		void getJacobsthalNumbersVector();
		void mergeInsertionSortVector(std::vector<std::pair<int, int> >& container, int low, int high);
		void mergeUsingInsertionVector(std::vector<std::pair<int, int> >& container, int low, int high);
		void sortUsingJacobsthalNumberVector(int low, int high, int num, std::vector<int>& result);

		void getJacobsthalNumbersList();
		void mergeInsertionSortList(std::list<std::pair<int, int> >& container, int low, int high);
		void mergeUsingInsertionList(std::list<std::pair<int, int> >& container, int low, int high);
		void sortUsingJacobsthalNumberList(int low, int high, int num, std::list<int>& result);
	public:
		~PmergeMe(void);
		std::vector<int> _before;
		std::vector<int> _after_vector;
		std::list<int> _after_list;
		double _v_time;
		double _l_time;
		static PmergeMe* getPmergeMe(char** argv);
		void sortVector(void);
		void sortList(void);
		void checkResult();
};

#endif
